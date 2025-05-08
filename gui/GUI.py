import tkinter as tk
from tkinter import messagebox, ttk
import serial
import serial.tools.list_ports
import folium
from geopy.distance import geodesic
import webbrowser
import threading
import time


# حساب المسافة الكلية
def calculate_total_distance(coords):
    total = 0.0
    for i in range(1, len(coords)):
        total += geodesic(coords[i-1], coords[i]).meters
    return total

def plot_folium_map(coords, output_file='map.html', auto_reload=False):
    if not coords:
        return

    total_distance = calculate_total_distance(coords)

    m = folium.Map(location=coords[0], zoom_start=16)
    folium.PolyLine(coords, color='blue', weight=3).add_to(m)
    folium.Marker(coords[0], popup='Start', icon=folium.Icon(color='green')).add_to(m)
    folium.Marker(coords[-1], popup='End', icon=folium.Icon(color='red')).add_to(m)

    title_html = f'''
         <div style="position: fixed; 
                     bottom: 50px; left: 50px; width: 300px; height: 50px; 
                     background-color: white; 
                     border:2px solid grey; 
                     z-index:9999; 
                     font-size:20px;
                     padding:10px;">
             Total Distance: {total_distance:.2f} meters
         </div>
         '''
    m.get_root().html.add_child(folium.Element(title_html))

    if auto_reload:
        reload_script = """
        <script>
            setTimeout(function(){
                window.location.reload(1);
            }, 10000);
        </script>
        """
        m.get_root().html.add_child(folium.Element(reload_script))

    m.save(output_file)

# فلترة الإحداثيات

def is_valid_coordinate(coord):
    lat, lon = coord
    return -90 <= lat <= 90 and -180 <= lon <= 180

def is_far_enough(p1, p2, min_distance=2):
    try:
        return geodesic(p1, p2).meters >= min_distance
    except:
        return False

def is_reasonable_jump(p1, p2, max_jump=50):
    try:
        return geodesic(p1, p2).meters <= max_jump
    except:
        return False


coordinates = []
reading = False

def get_available_ports():
    ports = serial.tools.list_ports.comports()
    return [port.device for port in ports]

def continuous_read():
    global coordinates, reading
    selected_port = port_var.get()
    if not selected_port:
        messagebox.showwarning("Port Not Selected", "Please select a COM port.")
        return

    try:
        with serial.Serial(selected_port, 9600, timeout=1) as ser:
            while reading:
                line = ser.readline().decode('ascii', errors='ignore').strip()
                if ',' in line:
                    try:
                        lat_str, lon_str = line.split(',')
                        lat = float(lat_str)
                        lon = float(lon_str)
                        new_coord = (lat, lon)

                        if is_valid_coordinate(new_coord):
                            if not coordinates:
                                coordinates.append(new_coord)
                            else:
                                last = coordinates[-1]
                                if is_far_enough(last, new_coord) and is_reasonable_jump(last, new_coord):
                                    coordinates.append(new_coord)
                                    print(f"Got: {lat}, {lon}")
                                    points_label.config(text=f"Points Read: {len(coordinates)}")
                    except ValueError:
                        pass
    except serial.SerialException as e:
        messagebox.showerror("Serial Error", str(e))

def start_reading():
    global reading, coordinates
    coordinates = []
    reading = True
    btn_start.config(state='disabled')
    btn_end.config(state='normal')

    plot_folium_map(coordinates, auto_reload=True)
    webbrowser.open('map.html')

    threading.Thread(target=continuous_read, daemon=True).start()

    def update_map_periodically():
        while reading:
            plot_folium_map(coordinates, auto_reload=True)
            time.sleep(10)

    threading.Thread(target=update_map_periodically, daemon=True).start()

def end_reading():
    global reading
    reading = False
    btn_start.config(state='normal')
    btn_end.config(state='disabled')
    messagebox.showinfo("Tracking Ended", f"Total points: {len(coordinates)}")
    plot_folium_map(coordinates, auto_reload=False)


# واجهة المستخدم GUI

root = tk.Tk()
root.title("GPS Tracker")

tk.Label(root, text="Select COM Port:").pack(pady=(10, 0))
port_var = tk.StringVar()
port_dropdown = ttk.Combobox(root, textvariable=port_var, values=[], width=30)
port_dropdown.pack(pady=5)

btn_start = tk.Button(root, text="Start Tracking", command=start_reading, width=30)
btn_start.pack(pady=5)

btn_end = tk.Button(root, text="End & Show Final Map", command=end_reading, width=30, state='disabled')
btn_end.pack(pady=5)


def refresh_ports():
    port_dropdown['values'] = get_available_ports()
    if port_dropdown['values']:
        port_dropdown.current(0)

tk.Button(root, text="Refresh Ports", command=refresh_ports).pack(pady=(0, 10))

points_label = tk.Label(root, text="Points Read: 0")
points_label.pack()

refresh_ports()
root.mainloop()
