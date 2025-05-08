#ifndef BIT_MATHS_H
#define BIT_MATHS_H

#define SET_BIT(REG,BIT) REG |= (1<<BIT)
#define CLR_BIT(REG,BIT) REG &= ~(1<<BIT)
#define TOG_BIT(REG,BIT) REG ^= (1<<BIT)
#define GET_BIT(REG,BIT) ((REG >> BIT)&1)

#define SET_MASK(REG,VALUE) REG |= (VALUE)
#define CLR_MASK(REG,VALUE) REG &=~(VALUE)
#define TOG_MASK(REG,VALUE) REG ^= (VALUE)
#define GET_MASK(REG,VALUE) ((REG )&(VALUE))

#endif
