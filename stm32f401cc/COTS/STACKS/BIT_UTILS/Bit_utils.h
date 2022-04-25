#ifndef BIT_MAN 
#define BIT_MAN


#define     SIZE_8          8
#define     SIZE_16         16
#define     SIZE_32         32

#define     REG_SIZE        SIZE_32

#if     REG_SIZE == SIZE_8

#define     SET_VAL     0xFF
#define     CLR_VAL     0x00

#elif   REG_SIZE == SIZE_16

#define     SET_VAL         0xFFFF
#define     CLR_VAL         0x0000

#elif   REG_SIZE == SIZE_32

#define     SET_VAL         0xFFFFFFFF
#define     CLR_VAL         0x00000000

#endif

#define SET_BIT(REG,BITNUM)    					REG |= (1 << BITNUM)
#define CLR_BIT(REG,BITNUM)  					REG &= ~(1 << BITNUM)
#define GET_BIT(REG,BITNUM)   				    ((REG >> BITNUM)&1)
#define RSHIFT_REG(REG,NO)                      REG = REG>>NO
#define LSHIFT_REG(REG,NO)                      REG = REG<<NO
#define CRSHIFT_REG(REG,NO)                     REG = (REG>>NO) | (REG<<(REG_SIZE-NO))
#define CLSHIFT_REG(REG,NO)                     REG = (REG<<NO) | (REG>>(REG_SIZE-NO))
#define ASSIGN_REG(REG,VALUE)                   REG = VALUE
#define SET_REG(REG)                            REG = SET_VAL
#define CLR_REG(REG)                            REG = CLR_VAL
#define TGL_BIT(REG,BITNUM) 					REG ^= (1 << BITNUM)
#define TGL_REG(REG)                            REG ^= SET_VAL
#define SET_H_NIB(REG)                          REG |= ( SET_VAL << (REG_SIZE/2) )
#define SET_L_NIB(REG)                          REG |= ( SET_VAL >> (REG_SIZE/2) )
#define CLR_H_NIB(REG)                          REG &= ( SET_VAL >> (REG_SIZE/2) )
#define CLR_L_NIB(REG)                          REG &= ( SET_VAL << (REG_SIZE/2) )
#define GET_H_NIB(REG)                          REG >> (REG_SIZE/2)
#define GET_L_NIB(REG)                          (REG & ( SET_VAL >> (REG_SIZE/2) ) )
#define ASSIGN_L_NIB(REG,VALUE)                 REG |= VALUE & (SET_VAL>>(REG_SIZE/2))
#define ASSIGN_H_NIB(REG,VALUE)                 REG |= ( VALUE << (REG_SIZE/2) )
#define TGL_H_NIB(REG)                          REG ^= ( SET_VAL << (REG_SIZE/2) )
#define TGL_L_NIB(REG)                          REG ^= ( SET_VAL >> (REG_SIZE/2) )
#define SWAP_NIB(REG)                           REG  = ( (REG >> (REG_SIZE/2) ) | (REG << (REG_SIZE/2) ) )

#endif

