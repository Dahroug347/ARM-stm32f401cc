/*
 * Nvic.h
 *
 *  Created on: May 15, 2022
 *      Author: dahroug
 */
#ifndef    NVIC_H_
#define    NVIC_H_

typedef enum
{
	NVIC_u8IRQ_NUM_0  ,
	NVIC_u8IRQ_NUM_1  ,
	NVIC_u8IRQ_NUM_2  ,
	NVIC_u8IRQ_NUM_3  ,
	NVIC_u8IRQ_NUM_4  ,
	NVIC_u8IRQ_NUM_5  ,
	NVIC_u8IRQ_NUM_6  ,
	NVIC_u8IRQ_NUM_7  ,
	NVIC_u8IRQ_NUM_8  ,
	NVIC_u8IRQ_NUM_9  ,
	NVIC_u8IRQ_NUM_10 ,
	NVIC_u8IRQ_NUM_11 ,
	NVIC_u8IRQ_NUM_12 ,
	NVIC_u8IRQ_NUM_13 ,
	NVIC_u8IRQ_NUM_14 ,
	NVIC_u8IRQ_NUM_15 ,
	NVIC_u8IRQ_NUM_16 ,
	NVIC_u8IRQ_NUM_17 ,
	NVIC_u8IRQ_NUM_18 ,
	NVIC_u8IRQ_NUM_19 ,
	NVIC_u8IRQ_NUM_20 ,
	NVIC_u8IRQ_NUM_21 ,
	NVIC_u8IRQ_NUM_22 ,
	NVIC_u8IRQ_NUM_23 ,
	NVIC_u8IRQ_NUM_24 ,
	NVIC_u8IRQ_NUM_25 ,
	NVIC_u8IRQ_NUM_26 ,
	NVIC_u8IRQ_NUM_27 ,
	NVIC_u8IRQ_NUM_28 ,
	NVIC_u8IRQ_NUM_29 ,
	NVIC_u8IRQ_NUM_30 ,
	NVIC_u8IRQ_NUM_31 ,
	NVIC_u8IRQ_NUM_32 ,
	NVIC_u8IRQ_NUM_33 ,
	NVIC_u8IRQ_NUM_34 ,
	NVIC_u8IRQ_NUM_35 ,
	NVIC_u8IRQ_NUM_36 ,
	NVIC_u8IRQ_NUM_37 ,
	NVIC_u8IRQ_NUM_38 ,
	NVIC_u8IRQ_NUM_39 ,
	NVIC_u8IRQ_NUM_40 ,
	NVIC_u8IRQ_NUM_41 ,
	NVIC_u8IRQ_NUM_42 ,
	NVIC_u8IRQ_NUM_43 ,
	NVIC_u8IRQ_NUM_44 ,
	NVIC_u8IRQ_NUM_45 ,
	NVIC_u8IRQ_NUM_46 ,
	NVIC_u8IRQ_NUM_47 ,
	NVIC_u8IRQ_NUM_48 ,
	NVIC_u8IRQ_NUM_49 ,
	NVIC_u8IRQ_NUM_50 ,
	NVIC_u8IRQ_NUM_51 ,
	NVIC_u8IRQ_NUM_52 ,
	NVIC_u8IRQ_NUM_53 ,
	NVIC_u8IRQ_NUM_54 ,
	NVIC_u8IRQ_NUM_55 ,
	NVIC_u8IRQ_NUM_56 ,
	NVIC_u8IRQ_NUM_57 ,
	NVIC_u8IRQ_NUM_58 ,
	NVIC_u8IRQ_NUM_59 ,
	NVIC_u8IRQ_NUM_60 ,
	NVIC_u8IRQ_NUM_61 ,
	NVIC_u8IRQ_NUM_62 ,
	NVIC_u8IRQ_NUM_63 ,
	NVIC_u8IRQ_NUM_64 ,
	NVIC_u8IRQ_NUM_65 ,
	NVIC_u8IRQ_NUM_66 ,
	NVIC_u8IRQ_NUM_67 ,
	NVIC_u8IRQ_NUM_68 ,
	NVIC_u8IRQ_NUM_69 ,
	NVIC_u8IRQ_NUM_70 ,
	NVIC_u8IRQ_NUM_71 ,
	NVIC_u8IRQ_NUM_72 ,
	NVIC_u8IRQ_NUM_73 ,
	NVIC_u8IRQ_NUM_74 ,
	NVIC_u8IRQ_NUM_75 ,
	NVIC_u8IRQ_NUM_76 ,
	NVIC_u8IRQ_NUM_77 ,
	NVIC_u8IRQ_NUM_78 ,
	NVIC_u8IRQ_NUM_79 ,
	NVIC_u8IRQ_NUM_80 ,
	NVIC_u8IRQ_NUM_81 ,
	NVIC_u8IRQ_NUM_82 ,
	NVIC_u8IRQ_NUM_83 ,
	NVIC_u8IRQ_NUM_84 ,
	NVIC_u8IRQ_NUM_85 ,
	NVIC_u8IRQ_NUM_86 ,
	NVIC_u8IRQ_NUM_87 ,
	NVIC_u8IRQ_NUM_88 ,
	NVIC_u8IRQ_NUM_89 ,
	NVIC_u8IRQ_NUM_90 ,
	NVIC_u8IRQ_NUM_91 ,
	NVIC_u8IRQ_NUM_92 ,
	NVIC_u8IRQ_NUM_93 ,
	NVIC_u8IRQ_NUM_94 ,
	NVIC_u8IRQ_NUM_95 ,
	NVIC_u8IRQ_NUM_96 ,
	NVIC_u8IRQ_NUM_97 ,
	NVIC_u8IRQ_NUM_98 ,
	NVIC_u8IRQ_NUM_99 ,
	NVIC_u8IRQ_NUM_100,
	NVIC_u8IRQ_NUM_101,
	NVIC_u8IRQ_NUM_102,
	NVIC_u8IRQ_NUM_103,
	NVIC_u8IRQ_NUM_104,
	NVIC_u8IRQ_NUM_105,
	NVIC_u8IRQ_NUM_106,
	NVIC_u8IRQ_NUM_107,
	NVIC_u8IRQ_NUM_108,
	NVIC_u8IRQ_NUM_109,
	NVIC_u8IRQ_NUM_110,
	NVIC_u8IRQ_NUM_111,
	NVIC_u8IRQ_NUM_112,
	NVIC_u8IRQ_NUM_113,
	NVIC_u8IRQ_NUM_114,
	NVIC_u8IRQ_NUM_115,
	NVIC_u8IRQ_NUM_116,
	NVIC_u8IRQ_NUM_117,
	NVIC_u8IRQ_NUM_118,
	NVIC_u8IRQ_NUM_119,
	NVIC_u8IRQ_NUM_120,
	NVIC_u8IRQ_NUM_121,
	NVIC_u8IRQ_NUM_122,
	NVIC_u8IRQ_NUM_123,
	NVIC_u8IRQ_NUM_124,
	NVIC_u8IRQ_NUM_125,
	NVIC_u8IRQ_NUM_126,
	NVIC_u8IRQ_NUM_127,
	NVIC_u8IRQ_NUM_128,
	NVIC_u8IRQ_NUM_129,
	NVIC_u8IRQ_NUM_130,
	NVIC_u8IRQ_NUM_131,
	NVIC_u8IRQ_NUM_132,
	NVIC_u8IRQ_NUM_133,
	NVIC_u8IRQ_NUM_134,
	NVIC_u8IRQ_NUM_135,
	NVIC_u8IRQ_NUM_136,
	NVIC_u8IRQ_NUM_137,
	NVIC_u8IRQ_NUM_138,
	NVIC_u8IRQ_NUM_139,
	NVIC_u8IRQ_NUM_140,
	NVIC_u8IRQ_NUM_141,
	NVIC_u8IRQ_NUM_142,
	NVIC_u8IRQ_NUM_143,
	NVIC_u8IRQ_NUM_144,
	NVIC_u8IRQ_NUM_145,
	NVIC_u8IRQ_NUM_146,
	NVIC_u8IRQ_NUM_147,
	NVIC_u8IRQ_NUM_148,
	NVIC_u8IRQ_NUM_149,
	NVIC_u8IRQ_NUM_150,
	NVIC_u8IRQ_NUM_151,
	NVIC_u8IRQ_NUM_152,
	NVIC_u8IRQ_NUM_153,
	NVIC_u8IRQ_NUM_154,
	NVIC_u8IRQ_NUM_155,
	NVIC_u8IRQ_NUM_156,
	NVIC_u8IRQ_NUM_157,
	NVIC_u8IRQ_NUM_158,
	NVIC_u8IRQ_NUM_159,
	NVIC_u8IRQ_NUM_160,
	NVIC_u8IRQ_NUM_161,
	NVIC_u8IRQ_NUM_162,
	NVIC_u8IRQ_NUM_163,
	NVIC_u8IRQ_NUM_164,
	NVIC_u8IRQ_NUM_165,
	NVIC_u8IRQ_NUM_166,
	NVIC_u8IRQ_NUM_167,
	NVIC_u8IRQ_NUM_168,
	NVIC_u8IRQ_NUM_169,
	NVIC_u8IRQ_NUM_170,
	NVIC_u8IRQ_NUM_171,
	NVIC_u8IRQ_NUM_172,
	NVIC_u8IRQ_NUM_173,
	NVIC_u8IRQ_NUM_174,
	NVIC_u8IRQ_NUM_175,
	NVIC_u8IRQ_NUM_176,
	NVIC_u8IRQ_NUM_177,
	NVIC_u8IRQ_NUM_178,
	NVIC_u8IRQ_NUM_179,
	NVIC_u8IRQ_NUM_180,
	NVIC_u8IRQ_NUM_181,
	NVIC_u8IRQ_NUM_182,
	NVIC_u8IRQ_NUM_183,
	NVIC_u8IRQ_NUM_184,
	NVIC_u8IRQ_NUM_185,
	NVIC_u8IRQ_NUM_186,
	NVIC_u8IRQ_NUM_187,
	NVIC_u8IRQ_NUM_188,
	NVIC_u8IRQ_NUM_189,
	NVIC_u8IRQ_NUM_190,
	NVIC_u8IRQ_NUM_191,
	NVIC_u8IRQ_NUM_192,
	NVIC_u8IRQ_NUM_193,
	NVIC_u8IRQ_NUM_194,
	NVIC_u8IRQ_NUM_195,
	NVIC_u8IRQ_NUM_196,
	NVIC_u8IRQ_NUM_197,
	NVIC_u8IRQ_NUM_198,
	NVIC_u8IRQ_NUM_199,
	NVIC_u8IRQ_NUM_200,
	NVIC_u8IRQ_NUM_201,
	NVIC_u8IRQ_NUM_202,
	NVIC_u8IRQ_NUM_203,
	NVIC_u8IRQ_NUM_204,
	NVIC_u8IRQ_NUM_205,
	NVIC_u8IRQ_NUM_206,
	NVIC_u8IRQ_NUM_207,
	NVIC_u8IRQ_NUM_208,
	NVIC_u8IRQ_NUM_209,
	NVIC_u8IRQ_NUM_210,
	NVIC_u8IRQ_NUM_211,
	NVIC_u8IRQ_NUM_212,
	NVIC_u8IRQ_NUM_213,
	NVIC_u8IRQ_NUM_214,
	NVIC_u8IRQ_NUM_215,
	NVIC_u8IRQ_NUM_216,
	NVIC_u8IRQ_NUM_217,
	NVIC_u8IRQ_NUM_218,
	NVIC_u8IRQ_NUM_219,
	NVIC_u8IRQ_NUM_220,
	NVIC_u8IRQ_NUM_221,
	NVIC_u8IRQ_NUM_222,
	NVIC_u8IRQ_NUM_223,
	NVIC_u8IRQ_NUM_224,
	NVIC_u8IRQ_NUM_225,
	NVIC_u8IRQ_NUM_226,
	NVIC_u8IRQ_NUM_227,
	NVIC_u8IRQ_NUM_228,
	NVIC_u8IRQ_NUM_229,
	NVIC_u8IRQ_NUM_230,
	NVIC_u8IRQ_NUM_231,
	NVIC_u8IRQ_NUM_232,
	NVIC_u8IRQ_NUM_233,
	NVIC_u8IRQ_NUM_234,
	NVIC_u8IRQ_NUM_235,
	NVIC_u8IRQ_NUM_236,
	NVIC_u8IRQ_NUM_237,
	NVIC_u8IRQ_NUM_238,
	NVIC_u8IRQ_NUM_239,

}IRQn_t;

typedef enum
{
	GRP16_SUB0,
	GRP8_SUB2 = 4,
	GRP4_SUB4,
	GRP2_SUB8,
	GRP0_SUB16
}PriorityCfg_t;


#define 	NVIC_IPR_GRP0		0x00
#define 	NVIC_IPR_GRP1		0x01
#define 	NVIC_IPR_GRP2		0x02
#define 	NVIC_IPR_GRP3 		0x03
#define 	NVIC_IPR_GRP4 		0x04
#define 	NVIC_IPR_GRP5 		0x05
#define 	NVIC_IPR_GRP6 		0x06
#define 	NVIC_IPR_GRP7 		0x07
#define 	NVIC_IPR_GRP8 		0x08
#define 	NVIC_IPR_GRP9 		0x09
#define 	NVIC_IPR_GRP10		0x0A
#define 	NVIC_IPR_GRP11		0x0B
#define 	NVIC_IPR_GRP12		0x0C
#define 	NVIC_IPR_GRP13		0x0D
#define 	NVIC_IPR_GRP14		0x0E
#define 	NVIC_IPR_GRP15		0x0F

#define 	NVIC_IPR_SUP0		0x00
#define 	NVIC_IPR_SUP1		0x01
#define 	NVIC_IPR_SUP2		0x02
#define 	NVIC_IPR_SUP3 		0x03
#define 	NVIC_IPR_SUP4 		0x04
#define 	NVIC_IPR_SUP5 		0x05
#define 	NVIC_IPR_SUP6 		0x06
#define 	NVIC_IPR_SUP7 		0x07
#define 	NVIC_IPR_SUP8 		0x08
#define 	NVIC_IPR_SUP9 		0x09
#define 	NVIC_IPR_SUP10		0x0A
#define 	NVIC_IPR_SUP11		0x0B
#define 	NVIC_IPR_SUP12		0x0C
#define 	NVIC_IPR_SUP13		0x0D
#define 	NVIC_IPR_SUP14		0x0E
#define 	NVIC_IPR_SUP15		0x0F

/*		Enable IRQn		*/
extern Std_enuErrorStatus NVIC_enuEnableIRQ(IRQn_t enu_tIRQn);

/*		Disable IRQn		*/
extern Std_enuErrorStatus NVIC_enuDisableIRQ(IRQn_t enu_tIRQn);

/*		Set IRQn pending		*/
extern Std_enuErrorStatus NVIC_enuSetPendingIRQ (IRQn_t enu_tIRQn);

/*		Clear IRQn pending status		*/
extern Std_enuErrorStatus NVIC_enuClearPendingIRQ (IRQn_t enu_tIRQn) ;

/*		Return the IRQ number of the active interrupt		*/
extern Std_enuErrorStatus NVIC_enuGetActive(IRQn_t enu_tIRQn,pu8 Add_pu8PendingStatus);

/*		 Set priority for IRQn		*/
extern Std_enuErrorStatus NVIC_enuSetPriority (IRQn_t enu_tIRQn, PriorityCfg_t Copy_tenuIPRCfg, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

/*		 Set NVIC priority configuration of group & sub-group */
extern Std_enuErrorStatus NVIC_enuConfigPriority (PriorityCfg_t Copy_tenuIPRCfg);


/*
NVIC_tenuErrorStatus NVIC_enuReallocateVectorTable(u32 Copy_u8VectorTableAddress);
void NVIC_enuEnableFaults(void);
void NVIC_enuDisableFaults(void);
*/
#endif /* MCAL_NVIC_NVIC_H_ */







