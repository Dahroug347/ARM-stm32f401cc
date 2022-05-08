#ifndef     RCC_H_
#define     RCC_H_

/* ________________________User CLock source selection Macros___________________________ */

#define 	RCC_HSI		                    ((u8)0)
#define 	RCC_HSE		                    ((u8)1)
#define 	RCC_PLL		                    ((u8)2)
#define 	RCC_PLLI2S		                ((u8)3)
#define 	RCC_LSI			                ((u8)4)
#define 	RCC_LSE			                ((u8)5)

#define 	RCC_CLK_OFF				        ((u8)0)
#define 	RCC_CLK_ON				        ((u8)1)

#define 	RCC_PERI_DIS					((u8)0)
#define 	RCC_PERI_EN						((u8)1)

/*BUS SElECTION MASKS FOR ENABLING PERIPHERALS*/
#define 	RCC_AHB1EN_BUS					((u8)0)
#define 	RCC_AHB2EN_BUS					((u8)1)
#define 	RCC_APB1EN_BUS					((u8)2)
#define 	RCC_APB2EN_BUS					((u8)3)
#define 	RCC_AHB1LPEN_BUS				((u8)4)
#define 	RCC_AHB2LPEN_BUS				((u8)5)
#define 	RCC_APB1LPEN_BUS				((u8)6)
#define 	RCC_APB2LPEN_BUS				((u8)7)
#define 	RCC_BDCR_EN						((u8)8)
#define 	RCC_SSCGR_EN					((u8)9)



/*___________________________ RCC_CR register MASKS___________________________ */
#define     RCC_CR_HSI_ON		            ((u32)0x00000001)
#define     RCC_CR_HSI_RDY		            ((u32)0x00000002)   // read only
#define     RCC_CR_HSE_ON		            ((u32)0x00010000)
#define     RCC_CR_HSE_RDY		            ((u32)0x00020000)	// read only
#define     RCC_CR_HSE_BYP		            ((u32)0x00040000)
#define     RCC_CR_CSS_ON		            ((u32)0x00080000)
#define     RCC_CR_PLL_ON		            ((u32)0x01000000)
#define     RCC_CR_PLL_RDY		            ((u32)0x02000000)	//read only
#define     RCC_CR_PLLI2S_ON	            ((u32)0x04000000)
#define     RCC_CR_PLLI2S_RDY	            ((u32)0x08000000)	//read only



/*___________________________ RCC_PLLCFGR register MASKS___________________________ */
/*PLL_M division factor*/
#define 	RCC_PLLCFGR_PLLM2	            ((u8)0x02)
#define 	RCC_PLLCFGR_PLLM3	            ((u8)0x03)
#define 	RCC_PLLCFGR_PLLM4	            ((u8)0x04)
#define 	RCC_PLLCFGR_PLLM5	            ((u8)0x05)
#define 	RCC_PLLCFGR_PLLM6	            ((u8)0x06)
#define 	RCC_PLLCFGR_PLLM7	            ((u8)0x07)
#define 	RCC_PLLCFGR_PLLM8	            ((u8)0x08)
#define 	RCC_PLLCFGR_PLLM9	            ((u8)0x09)
#define 	RCC_PLLCFGR_PLLM10	            ((u8)0x0A)
#define 	RCC_PLLCFGR_PLLM11	            ((u8)0x0B)
#define 	RCC_PLLCFGR_PLLM12	            ((u8)0x0C)
#define 	RCC_PLLCFGR_PLLM13	            ((u8)0x0D)
#define 	RCC_PLLCFGR_PLLM14	            ((u8)0x0E)
#define 	RCC_PLLCFGR_PLLM15	            ((u8)0x0F)
#define 	RCC_PLLCFGR_PLLM16	            ((u8)0x10)
#define 	RCC_PLLCFGR_PLLM17	            ((u8)0x11)
#define 	RCC_PLLCFGR_PLLM18	            ((u8)0x12)
#define 	RCC_PLLCFGR_PLLM19	            ((u8)0x13)
#define 	RCC_PLLCFGR_PLLM20	            ((u8)0x14)
#define 	RCC_PLLCFGR_PLLM21	            ((u8)0x15)
#define 	RCC_PLLCFGR_PLLM22	            ((u8)0x16)
#define 	RCC_PLLCFGR_PLLM23	            ((u8)0x17)
#define 	RCC_PLLCFGR_PLLM24	            ((u8)0x18)
#define 	RCC_PLLCFGR_PLLM25	            ((u8)0x19)
#define 	RCC_PLLCFGR_PLLM26	            ((u8)0x1A)
#define 	RCC_PLLCFGR_PLLM27	            ((u8)0x1B)
#define 	RCC_PLLCFGR_PLLM28	            ((u8)0x1C)
#define 	RCC_PLLCFGR_PLLM29	            ((u8)0x1D)
#define 	RCC_PLLCFGR_PLLM30	            ((u8)0x1E)
#define 	RCC_PLLCFGR_PLLM31	            ((u8)0x1F)
#define 	RCC_PLLCFGR_PLLM32	            ((u8)0x20)
#define 	RCC_PLLCFGR_PLLM33	            ((u8)0x21)
#define 	RCC_PLLCFGR_PLLM34	            ((u8)0x22)
#define 	RCC_PLLCFGR_PLLM35	            ((u8)0x23)
#define 	RCC_PLLCFGR_PLLM36	            ((u8)0x24)
#define 	RCC_PLLCFGR_PLLM37	            ((u8)0x25)
#define 	RCC_PLLCFGR_PLLM38	            ((u8)0x26)
#define 	RCC_PLLCFGR_PLLM39	            ((u8)0x27)
#define 	RCC_PLLCFGR_PLLM40	            ((u8)0x28)
#define 	RCC_PLLCFGR_PLLM41	            ((u8)0x29)
#define 	RCC_PLLCFGR_PLLM42	            ((u8)0x2A)
#define 	RCC_PLLCFGR_PLLM43	            ((u8)0x2B)
#define 	RCC_PLLCFGR_PLLM44	            ((u8)0x2C)
#define 	RCC_PLLCFGR_PLLM45	            ((u8)0x2D)
#define 	RCC_PLLCFGR_PLLM46	            ((u8)0x2E)
#define 	RCC_PLLCFGR_PLLM47	            ((u8)0x2F)
#define 	RCC_PLLCFGR_PLLM48	            ((u8)0x30)
#define 	RCC_PLLCFGR_PLLM49	            ((u8)0x31)
#define 	RCC_PLLCFGR_PLLM50	            ((u8)0x32)
#define 	RCC_PLLCFGR_PLLM51	            ((u8)0x33)
#define 	RCC_PLLCFGR_PLLM52	            ((u8)0x34)
#define 	RCC_PLLCFGR_PLLM53	            ((u8)0x35)
#define 	RCC_PLLCFGR_PLLM54	            ((u8)0x36)
#define 	RCC_PLLCFGR_PLLM55	            ((u8)0x37)
#define 	RCC_PLLCFGR_PLLM56	            ((u8)0x38)
#define 	RCC_PLLCFGR_PLLM57	            ((u8)0x39)
#define 	RCC_PLLCFGR_PLLM58	            ((u8)0x3A)
#define 	RCC_PLLCFGR_PLLM59	            ((u8)0x3B)
#define 	RCC_PLLCFGR_PLLM60	            ((u8)0x3C)
#define 	RCC_PLLCFGR_PLLM61	            ((u8)0x3D)
#define 	RCC_PLLCFGR_PLLM62	            ((u8)0x3E)
#define 	RCC_PLLCFGR_PLLM63	            ((u8)0x3F)

/*PLL_N Multiplier factor*/
#define 	RCC_PLLCFGR_PLLN192	            ((u16)0x00C0)
#define 	RCC_PLLCFGR_PLLN193	            ((u16)0x00C1)
#define 	RCC_PLLCFGR_PLLN194	            ((u16)0x00C2)
#define 	RCC_PLLCFGR_PLLN195	            ((u16)0x00C3)
#define 	RCC_PLLCFGR_PLLN196	            ((u16)0x00C4)
#define 	RCC_PLLCFGR_PLLN197	            ((u16)0x00C5)
#define 	RCC_PLLCFGR_PLLN198	            ((u16)0x00C6)
#define 	RCC_PLLCFGR_PLLN199	            ((u16)0x00C7)
#define 	RCC_PLLCFGR_PLLN200	            ((u16)0x00C8)
#define 	RCC_PLLCFGR_PLLN201	            ((u16)0x00C9)
#define 	RCC_PLLCFGR_PLLN202	            ((u16)0x00CA)
#define 	RCC_PLLCFGR_PLLN203	            ((u16)0x00CB)
#define 	RCC_PLLCFGR_PLLN204	            ((u16)0x00CC)
#define 	RCC_PLLCFGR_PLLN205	            ((u16)0x00CD)
#define 	RCC_PLLCFGR_PLLN206	            ((u16)0x00CE)
#define 	RCC_PLLCFGR_PLLN207	            ((u16)0x00CF)
#define 	RCC_PLLCFGR_PLLN208	            ((u16)0x00D0)
#define 	RCC_PLLCFGR_PLLN209	            ((u16)0x00D1)
#define 	RCC_PLLCFGR_PLLN210	            ((u16)0x00D2)
#define 	RCC_PLLCFGR_PLLN211	            ((u16)0x00D3)
#define 	RCC_PLLCFGR_PLLN212	            ((u16)0x00D4)
#define 	RCC_PLLCFGR_PLLN213	            ((u16)0x00D5)
#define 	RCC_PLLCFGR_PLLN214	            ((u16)0x00D6)
#define 	RCC_PLLCFGR_PLLN215	            ((u16)0x00D7)
#define 	RCC_PLLCFGR_PLLN216	            ((u16)0x00D8)
#define 	RCC_PLLCFGR_PLLN217	            ((u16)0x00D9)
#define 	RCC_PLLCFGR_PLLN218	            ((u16)0x00DA)
#define 	RCC_PLLCFGR_PLLN219	            ((u16)0x00DB)
#define 	RCC_PLLCFGR_PLLN220	            ((u16)0x00DC)
#define 	RCC_PLLCFGR_PLLN221	            ((u16)0x00DD)
#define 	RCC_PLLCFGR_PLLN222	            ((u16)0x00DE)
#define 	RCC_PLLCFGR_PLLN223	            ((u16)0x00DF)
#define 	RCC_PLLCFGR_PLLN224	            ((u16)0x00E0)
#define 	RCC_PLLCFGR_PLLN225	            ((u16)0x00E1)
#define 	RCC_PLLCFGR_PLLN226	            ((u16)0x00E2)
#define 	RCC_PLLCFGR_PLLN227	            ((u16)0x00E3)
#define 	RCC_PLLCFGR_PLLN228	            ((u16)0x00E4)
#define 	RCC_PLLCFGR_PLLN229	            ((u16)0x00E5)
#define 	RCC_PLLCFGR_PLLN230	            ((u16)0x00E6)
#define 	RCC_PLLCFGR_PLLN231	            ((u16)0x00E7)
#define 	RCC_PLLCFGR_PLLN232	            ((u16)0x00E8)
#define 	RCC_PLLCFGR_PLLN233	            ((u16)0x00E9)
#define 	RCC_PLLCFGR_PLLN234	            ((u16)0x00EA)
#define 	RCC_PLLCFGR_PLLN235	            ((u16)0x00EB)
#define 	RCC_PLLCFGR_PLLN236	            ((u16)0x00EC)
#define 	RCC_PLLCFGR_PLLN237	            ((u16)0x00ED)
#define 	RCC_PLLCFGR_PLLN238	            ((u16)0x00EE)
#define 	RCC_PLLCFGR_PLLN239	            ((u16)0x00EF)
#define 	RCC_PLLCFGR_PLLN240	            ((u16)0x00F0)
#define 	RCC_PLLCFGR_PLLN241	            ((u16)0x00F1)
#define 	RCC_PLLCFGR_PLLN242	            ((u16)0x00F2)
#define 	RCC_PLLCFGR_PLLN243	            ((u16)0x00F3)
#define 	RCC_PLLCFGR_PLLN244	            ((u16)0x00F4)
#define 	RCC_PLLCFGR_PLLN245	            ((u16)0x00F5)
#define 	RCC_PLLCFGR_PLLN246	            ((u16)0x00F6)
#define 	RCC_PLLCFGR_PLLN247	            ((u16)0x00F7)
#define 	RCC_PLLCFGR_PLLN248	            ((u16)0x00F8)
#define 	RCC_PLLCFGR_PLLN249	            ((u16)0x00F9)
#define 	RCC_PLLCFGR_PLLN250	            ((u16)0x00FA)
#define 	RCC_PLLCFGR_PLLN251	            ((u16)0x00FB)
#define 	RCC_PLLCFGR_PLLN252	            ((u16)0x00FC)
#define 	RCC_PLLCFGR_PLLN253	            ((u16)0x00FD)
#define 	RCC_PLLCFGR_PLLN254	            ((u16)0x00FE)
#define 	RCC_PLLCFGR_PLLN255	            ((u16)0x00FF)
#define 	RCC_PLLCFGR_PLLN256	            ((u16)0x0100)
#define 	RCC_PLLCFGR_PLLN257	            ((u16)0x0101)
#define 	RCC_PLLCFGR_PLLN258	            ((u16)0x0102)
#define 	RCC_PLLCFGR_PLLN259	            ((u16)0x0103)
#define 	RCC_PLLCFGR_PLLN260	            ((u16)0x0104)
#define 	RCC_PLLCFGR_PLLN261	            ((u16)0x0105)
#define 	RCC_PLLCFGR_PLLN262	            ((u16)0x0106)
#define 	RCC_PLLCFGR_PLLN263	            ((u16)0x0107)
#define 	RCC_PLLCFGR_PLLN264	            ((u16)0x0108)
#define 	RCC_PLLCFGR_PLLN265	            ((u16)0x0109)
#define 	RCC_PLLCFGR_PLLN266	            ((u16)0x010A)
#define 	RCC_PLLCFGR_PLLN267	            ((u16)0x010B)
#define 	RCC_PLLCFGR_PLLN268	            ((u16)0x010C)
#define 	RCC_PLLCFGR_PLLN269	            ((u16)0x010D)
#define 	RCC_PLLCFGR_PLLN270	            ((u16)0x010E)
#define 	RCC_PLLCFGR_PLLN271	            ((u16)0x010F)
#define 	RCC_PLLCFGR_PLLN272	            ((u16)0x0110)
#define 	RCC_PLLCFGR_PLLN273	            ((u16)0x0111)
#define 	RCC_PLLCFGR_PLLN274	            ((u16)0x0112)
#define 	RCC_PLLCFGR_PLLN275	            ((u16)0x0113)
#define 	RCC_PLLCFGR_PLLN276	            ((u16)0x0114)
#define 	RCC_PLLCFGR_PLLN277	            ((u16)0x0115)
#define 	RCC_PLLCFGR_PLLN278	            ((u16)0x0116)
#define 	RCC_PLLCFGR_PLLN279	            ((u16)0x0117)
#define 	RCC_PLLCFGR_PLLN280	            ((u16)0x0118)
#define 	RCC_PLLCFGR_PLLN281	            ((u16)0x0119)
#define 	RCC_PLLCFGR_PLLN282	            ((u16)0x011A)
#define 	RCC_PLLCFGR_PLLN283	            ((u16)0x011B)
#define 	RCC_PLLCFGR_PLLN284	            ((u16)0x011C)
#define 	RCC_PLLCFGR_PLLN285	            ((u16)0x011D)
#define 	RCC_PLLCFGR_PLLN286	            ((u16)0x011E)
#define 	RCC_PLLCFGR_PLLN287	            ((u16)0x011F)
#define 	RCC_PLLCFGR_PLLN288	            ((u16)0x0120)
#define 	RCC_PLLCFGR_PLLN289	            ((u16)0x0121)
#define 	RCC_PLLCFGR_PLLN290	            ((u16)0x0122)
#define 	RCC_PLLCFGR_PLLN291	            ((u16)0x0123)
#define 	RCC_PLLCFGR_PLLN292	            ((u16)0x0124)
#define 	RCC_PLLCFGR_PLLN293	            ((u16)0x0125)
#define 	RCC_PLLCFGR_PLLN294	            ((u16)0x0126)
#define 	RCC_PLLCFGR_PLLN295	            ((u16)0x0127)
#define 	RCC_PLLCFGR_PLLN296	            ((u16)0x0128)
#define 	RCC_PLLCFGR_PLLN297	            ((u16)0x0129)
#define 	RCC_PLLCFGR_PLLN298	            ((u16)0x012A)
#define 	RCC_PLLCFGR_PLLN299	            ((u16)0x012B)
#define 	RCC_PLLCFGR_PLLN300	            ((u16)0x012C)
#define 	RCC_PLLCFGR_PLLN301	            ((u16)0x012D)
#define 	RCC_PLLCFGR_PLLN302	            ((u16)0x012E)
#define 	RCC_PLLCFGR_PLLN303	            ((u16)0x012F)
#define 	RCC_PLLCFGR_PLLN304	            ((u16)0x0130)
#define 	RCC_PLLCFGR_PLLN305	            ((u16)0x0131)
#define 	RCC_PLLCFGR_PLLN306	            ((u16)0x0132)
#define 	RCC_PLLCFGR_PLLN307	            ((u16)0x0133)
#define 	RCC_PLLCFGR_PLLN308	            ((u16)0x0134)
#define 	RCC_PLLCFGR_PLLN309	            ((u16)0x0135)
#define 	RCC_PLLCFGR_PLLN310	            ((u16)0x0136)
#define 	RCC_PLLCFGR_PLLN311	            ((u16)0x0137)
#define 	RCC_PLLCFGR_PLLN312	            ((u16)0x0138)
#define 	RCC_PLLCFGR_PLLN313	            ((u16)0x0139)
#define 	RCC_PLLCFGR_PLLN314	            ((u16)0x013A)
#define 	RCC_PLLCFGR_PLLN315	            ((u16)0x013B)
#define 	RCC_PLLCFGR_PLLN316	            ((u16)0x013C)
#define 	RCC_PLLCFGR_PLLN317	            ((u16)0x013D)
#define 	RCC_PLLCFGR_PLLN318	            ((u16)0x013E)
#define 	RCC_PLLCFGR_PLLN319	            ((u16)0x013F)
#define 	RCC_PLLCFGR_PLLN320	            ((u16)0x0140)
#define 	RCC_PLLCFGR_PLLN321	            ((u16)0x0141)
#define 	RCC_PLLCFGR_PLLN322	            ((u16)0x0142)
#define 	RCC_PLLCFGR_PLLN323	            ((u16)0x0143)
#define 	RCC_PLLCFGR_PLLN324	            ((u16)0x0144)
#define 	RCC_PLLCFGR_PLLN325	            ((u16)0x0145)
#define 	RCC_PLLCFGR_PLLN326	            ((u16)0x0146)
#define 	RCC_PLLCFGR_PLLN327	            ((u16)0x0147)
#define 	RCC_PLLCFGR_PLLN328	            ((u16)0x0148)
#define 	RCC_PLLCFGR_PLLN329	            ((u16)0x0149)
#define 	RCC_PLLCFGR_PLLN330	            ((u16)0x014A)
#define 	RCC_PLLCFGR_PLLN331	            ((u16)0x014B)
#define 	RCC_PLLCFGR_PLLN332	            ((u16)0x014C)
#define 	RCC_PLLCFGR_PLLN333	            ((u16)0x014D)
#define 	RCC_PLLCFGR_PLLN334	            ((u16)0x014E)
#define 	RCC_PLLCFGR_PLLN335	            ((u16)0x014F)
#define 	RCC_PLLCFGR_PLLN336	            ((u16)0x0150)
#define 	RCC_PLLCFGR_PLLN337	            ((u16)0x0151)
#define 	RCC_PLLCFGR_PLLN338	            ((u16)0x0152)
#define 	RCC_PLLCFGR_PLLN339	            ((u16)0x0153)
#define 	RCC_PLLCFGR_PLLN340	            ((u16)0x0154)
#define 	RCC_PLLCFGR_PLLN341	            ((u16)0x0155)
#define 	RCC_PLLCFGR_PLLN342	            ((u16)0x0156)
#define 	RCC_PLLCFGR_PLLN343	            ((u16)0x0157)
#define 	RCC_PLLCFGR_PLLN344	            ((u16)0x0158)
#define 	RCC_PLLCFGR_PLLN345	            ((u16)0x0159)
#define 	RCC_PLLCFGR_PLLN346	            ((u16)0x015A)
#define 	RCC_PLLCFGR_PLLN347	            ((u16)0x015B)
#define 	RCC_PLLCFGR_PLLN348	            ((u16)0x015C)
#define 	RCC_PLLCFGR_PLLN349	            ((u16)0x015D)
#define 	RCC_PLLCFGR_PLLN350	            ((u16)0x015E)
#define 	RCC_PLLCFGR_PLLN351	            ((u16)0x015F)
#define 	RCC_PLLCFGR_PLLN352	            ((u16)0x0160)
#define 	RCC_PLLCFGR_PLLN353	            ((u16)0x0161)
#define 	RCC_PLLCFGR_PLLN354	            ((u16)0x0162)
#define 	RCC_PLLCFGR_PLLN355	            ((u16)0x0163)
#define 	RCC_PLLCFGR_PLLN356	            ((u16)0x0164)
#define 	RCC_PLLCFGR_PLLN357	            ((u16)0x0165)
#define 	RCC_PLLCFGR_PLLN358	            ((u16)0x0166)
#define 	RCC_PLLCFGR_PLLN359	            ((u16)0x0167)
#define 	RCC_PLLCFGR_PLLN360	            ((u16)0x0168)
#define 	RCC_PLLCFGR_PLLN361	            ((u16)0x0169)
#define 	RCC_PLLCFGR_PLLN362	            ((u16)0x016A)
#define 	RCC_PLLCFGR_PLLN363	            ((u16)0x016B)
#define 	RCC_PLLCFGR_PLLN364	            ((u16)0x016C)
#define 	RCC_PLLCFGR_PLLN365	            ((u16)0x016D)
#define 	RCC_PLLCFGR_PLLN366	            ((u16)0x016E)
#define 	RCC_PLLCFGR_PLLN367	            ((u16)0x016F)
#define 	RCC_PLLCFGR_PLLN368	            ((u16)0x0170)
#define 	RCC_PLLCFGR_PLLN369	            ((u16)0x0171)
#define 	RCC_PLLCFGR_PLLN370	            ((u16)0x0172)
#define 	RCC_PLLCFGR_PLLN371	            ((u16)0x0173)
#define 	RCC_PLLCFGR_PLLN372	            ((u16)0x0174)
#define 	RCC_PLLCFGR_PLLN373	            ((u16)0x0175)
#define 	RCC_PLLCFGR_PLLN374	            ((u16)0x0176)
#define 	RCC_PLLCFGR_PLLN375	            ((u16)0x0177)
#define 	RCC_PLLCFGR_PLLN376	            ((u16)0x0178)
#define 	RCC_PLLCFGR_PLLN377	            ((u16)0x0179)
#define 	RCC_PLLCFGR_PLLN378	            ((u16)0x017A)
#define 	RCC_PLLCFGR_PLLN379	            ((u16)0x017B)
#define 	RCC_PLLCFGR_PLLN380	            ((u16)0x017C)
#define 	RCC_PLLCFGR_PLLN381	            ((u16)0x017D)
#define 	RCC_PLLCFGR_PLLN382	            ((u16)0x017E)
#define 	RCC_PLLCFGR_PLLN383	            ((u16)0x017F)
#define 	RCC_PLLCFGR_PLLN384	            ((u16)0x0180)
#define 	RCC_PLLCFGR_PLLN385	            ((u16)0x0181)
#define 	RCC_PLLCFGR_PLLN386	            ((u16)0x0182)
#define 	RCC_PLLCFGR_PLLN387	            ((u16)0x0183)
#define 	RCC_PLLCFGR_PLLN388	            ((u16)0x0184)
#define 	RCC_PLLCFGR_PLLN389	            ((u16)0x0185)
#define 	RCC_PLLCFGR_PLLN390	            ((u16)0x0186)
#define 	RCC_PLLCFGR_PLLN391	            ((u16)0x0187)
#define 	RCC_PLLCFGR_PLLN392	            ((u16)0x0188)
#define 	RCC_PLLCFGR_PLLN393	            ((u16)0x0189)
#define 	RCC_PLLCFGR_PLLN394	            ((u16)0x018A)
#define 	RCC_PLLCFGR_PLLN395	            ((u16)0x018B)
#define 	RCC_PLLCFGR_PLLN396	            ((u16)0x018C)
#define 	RCC_PLLCFGR_PLLN397	            ((u16)0x018D)
#define 	RCC_PLLCFGR_PLLN398	            ((u16)0x018E)
#define 	RCC_PLLCFGR_PLLN399	            ((u16)0x018F)
#define 	RCC_PLLCFGR_PLLN400	            ((u16)0x0190)
#define 	RCC_PLLCFGR_PLLN401	            ((u16)0x0191)
#define 	RCC_PLLCFGR_PLLN402	            ((u16)0x0192)
#define 	RCC_PLLCFGR_PLLN403	            ((u16)0x0193)
#define 	RCC_PLLCFGR_PLLN404	            ((u16)0x0194)
#define 	RCC_PLLCFGR_PLLN405	            ((u16)0x0195)
#define 	RCC_PLLCFGR_PLLN406	            ((u16)0x0196)
#define 	RCC_PLLCFGR_PLLN407	            ((u16)0x0197)
#define 	RCC_PLLCFGR_PLLN408	            ((u16)0x0198)
#define 	RCC_PLLCFGR_PLLN409	            ((u16)0x0199)
#define 	RCC_PLLCFGR_PLLN410	            ((u16)0x019A)
#define 	RCC_PLLCFGR_PLLN411	            ((u16)0x019B)
#define 	RCC_PLLCFGR_PLLN412	            ((u16)0x019C)
#define 	RCC_PLLCFGR_PLLN413	            ((u16)0x019D)
#define 	RCC_PLLCFGR_PLLN414	            ((u16)0x019E)
#define 	RCC_PLLCFGR_PLLN415	            ((u16)0x019F)
#define 	RCC_PLLCFGR_PLLN416	            ((u16)0x01A0)
#define 	RCC_PLLCFGR_PLLN417	            ((u16)0x01A1)
#define 	RCC_PLLCFGR_PLLN418	            ((u16)0x01A2)
#define 	RCC_PLLCFGR_PLLN419	            ((u16)0x01A3)
#define 	RCC_PLLCFGR_PLLN420	            ((u16)0x01A4)
#define 	RCC_PLLCFGR_PLLN421	            ((u16)0x01A5)
#define 	RCC_PLLCFGR_PLLN422	            ((u16)0x01A6)
#define 	RCC_PLLCFGR_PLLN423	            ((u16)0x01A7)
#define 	RCC_PLLCFGR_PLLN424	            ((u16)0x01A8)
#define 	RCC_PLLCFGR_PLLN425	            ((u16)0x01A9)
#define 	RCC_PLLCFGR_PLLN426	            ((u16)0x01AA)
#define 	RCC_PLLCFGR_PLLN427	            ((u16)0x01AB)
#define 	RCC_PLLCFGR_PLLN428	            ((u16)0x01AC)
#define 	RCC_PLLCFGR_PLLN429	            ((u16)0x01AD)
#define 	RCC_PLLCFGR_PLLN430	            ((u16)0x01AE)
#define 	RCC_PLLCFGR_PLLN431	            ((u16)0x01AF)
#define 	RCC_PLLCFGR_PLLN432	            ((u16)0x01B0)

/*PLL_P Division factor*/
#define 	RCC_PLLCFGR_PLLP2	            ((u8)0x00)
#define 	RCC_PLLCFGR_PLLP4	            ((u8)0x01)
#define 	RCC_PLLCFGR_PLLP6	            ((u8)0x02)
#define 	RCC_PLLCFGR_PLLP8	            ((u8)0x03)

/*PLL CLK SRC*/
#define 	RCC_PLLCFGR_PLLSRC_HSI		    ((u32)0x00000000)
#define 	RCC_PLLCFGR_PLLSRC_HSE		    ((u32)0x00400000)

/*PLL_Q division factor*/
#define	    RCC_PLLCFGR_PLLQ2	            ((u8)0x02)
#define	    RCC_PLLCFGR_PLLQ3	            ((u8)0x03)
#define	    RCC_PLLCFGR_PLLQ4	            ((u8)0x04)
#define	    RCC_PLLCFGR_PLLQ5	            ((u8)0x05)
#define	    RCC_PLLCFGR_PLLQ6	            ((u8)0x06)
#define	    RCC_PLLCFGR_PLLQ7	            ((u8)0x07)
#define	    RCC_PLLCFGR_PLLQ8	            ((u8)0x08)
#define	    RCC_PLLCFGR_PLLQ9	            ((u8)0x09)
#define	    RCC_PLLCFGR_PLLQ10	            ((u8)0x0A)
#define	    RCC_PLLCFGR_PLLQ11	            ((u8)0x0B)
#define	    RCC_PLLCFGR_PLLQ12	            ((u8)0x0C)
#define	    RCC_PLLCFGR_PLLQ13	            ((u8)0x0D)
#define	    RCC_PLLCFGR_PLLQ14	            ((u8)0x0E)
#define	    RCC_PLLCFGR_PLLQ15	            ((u8)0x0F)



/*___________________________ RCC_CFGR register MASKS___________________________ */
#define 	RCC_CFGR_SW_PLL		        	((u32)0x00000002)
#define 	RCC_CFGR_SW_HSI		        	((u32)0x00000000)
#define 	RCC_CFGR_SW_HSE		        	((u32)0x00000001)

#define 	RCC_CFGR_SWS_PLL		        ((u32)0x00000008)
#define 	RCC_CFGR_SWS_HSI		        ((u32)0x00000000)
#define 	RCC_CFGR_SWS_HSE		        ((u32)0x00000004)

#define 	RCC_CFGR_HPRE1_0	            ((u8)0x00)
#define 	RCC_CFGR_HPRE1_1	            ((u8)0x01)
#define 	RCC_CFGR_HPRE1_2	            ((u8)0x02)
#define 	RCC_CFGR_HPRE1_3                ((u8)0x03)
#define 	RCC_CFGR_HPRE1_4	            ((u8)0x04)
#define 	RCC_CFGR_HPRE1_5	            ((u8)0x05)
#define 	RCC_CFGR_HPRE1_6	            ((u8)0x06)
#define 	RCC_CFGR_HPRE1_7	            ((u8)0x07)
#define 	RCC_CFGR_HPRE2	                ((u8)0x08)
#define 	RCC_CFGR_HPRE4	                ((u8)0x09)
#define 	RCC_CFGR_HPRE8	                ((u8)0x0A)
#define 	RCC_CFGR_HPRE16	                ((u8)0x0B)
#define 	RCC_CFGR_HPRE64	                ((u8)0x0C)
#define 	RCC_CFGR_HPRE128	            ((u8)0x0D)
#define 	RCC_CFGR_HPRE256	            ((u8)0x0E)
#define 	RCC_CFGR_HPRE512	            ((u8)0x0F)

#define 	RCC_CFGR_PPRE1_1_0	            ((u8)0x00)
#define 	RCC_CFGR_PPRE1_1_1	            ((u8)0x01)
#define 	RCC_CFGR_PPRE1_1_2	            ((u8)0x02)
#define 	RCC_CFGR_PPRE1_1_3	            ((u8)0x03)
#define 	RCC_CFGR_PPRE1_2	            ((u8)0x04)
#define 	RCC_CFGR_PPRE1_4	            ((u8)0x05)
#define 	RCC_CFGR_PPRE1_8	            ((u8)0x06)
#define 	RCC_CFGR_PPRE1_16	        	((u8)0x07)

#define 	RCC_CFGR_PPRE2_1_0	            ((u8)0x00)
#define 	RCC_CFGR_PPRE2_1_1	            ((u8)0x01)
#define 	RCC_CFGR_PPRE2_1_2	            ((u8)0x02)
#define 	RCC_CFGR_PPRE2_1_3	            ((u8)0x03)
#define 	RCC_CFGR_PPRE2_2	            ((u8)0x04)
#define 	RCC_CFGR_PPRE2_4	            ((u8)0x05)
#define 	RCC_CFGR_PPRE2_8	            ((u8)0x06)
#define 	RCC_CFGR_PPRE2_16	        	((u8)0x07)

#define 	RCC_CFGR_RTCPRE_HSE1_0	        ((u32)0x00000000)
#define 	RCC_CFGR_RTCPRE_HSE1_1	        ((u32)0x00010000)
#define 	RCC_CFGR_RTCPRE_HSE2	        ((u32)0x00020000)
#define 	RCC_CFGR_RTCPRE_HSE3	        ((u32)0x00030000)
#define 	RCC_CFGR_RTCPRE_HSE4	        ((u32)0x00040000)
#define 	RCC_CFGR_RTCPRE_HSE5	        ((u32)0x00050000)
#define 	RCC_CFGR_RTCPRE_HSE6	        ((u32)0x00060000)
#define 	RCC_CFGR_RTCPRE_HSE7	        ((u32)0x00070000)
#define 	RCC_CFGR_RTCPRE_HSE8	        ((u32)0x00080000)
#define 	RCC_CFGR_RTCPRE_HSE9	        ((u32)0x00090000)
#define 	RCC_CFGR_RTCPRE_HSE10	        ((u32)0x000A0000)
#define 	RCC_CFGR_RTCPRE_HSE11	        ((u32)0x000B0000)
#define 	RCC_CFGR_RTCPRE_HSE12	        ((u32)0x000C0000)
#define 	RCC_CFGR_RTCPRE_HSE13	        ((u32)0x000D0000)
#define 	RCC_CFGR_RTCPRE_HSE14	        ((u32)0x000E0000)
#define 	RCC_CFGR_RTCPRE_HSE15	        ((u32)0x000F0000)
#define 	RCC_CFGR_RTCPRE_HSE16	        ((u32)0x00100000)
#define 	RCC_CFGR_RTCPRE_HSE17	        ((u32)0x00110000)
#define 	RCC_CFGR_RTCPRE_HSE18	        ((u32)0x00120000)
#define 	RCC_CFGR_RTCPRE_HSE19	        ((u32)0x00130000)
#define 	RCC_CFGR_RTCPRE_HSE20	        ((u32)0x00140000)
#define 	RCC_CFGR_RTCPRE_HSE21	        ((u32)0x00150000)
#define 	RCC_CFGR_RTCPRE_HSE22	        ((u32)0x00160000)
#define 	RCC_CFGR_RTCPRE_HSE23	        ((u32)0x00170000)
#define 	RCC_CFGR_RTCPRE_HSE24	        ((u32)0x00180000)
#define 	RCC_CFGR_RTCPRE_HSE25	        ((u32)0x00190000)
#define 	RCC_CFGR_RTCPRE_HSE26	        ((u32)0x001A0000)
#define 	RCC_CFGR_RTCPRE_HSE27	        ((u32)0x001B0000)
#define 	RCC_CFGR_RTCPRE_HSE28	        ((u32)0x001C0000)
#define 	RCC_CFGR_RTCPRE_HSE29	        ((u32)0x001D0000)
#define 	RCC_CFGR_RTCPRE_HSE30	        ((u32)0x001E0000)
#define 	RCC_CFGR_RTCPRE_HSE31	        ((u32)0x001F0000)

#define 	RCC_CFGR_MCO1_HSI		        ((u32)0x00000000)
#define 	RCC_CFGR_MCO1_LSE		        ((u32)0x00200000)
#define 	RCC_CFGR_MCO1_HSE		        ((u32)0x00400000)
#define 	RCC_CFGR_MCO1_PLL		        ((u32)0x00600000)

#define 	RCC_CFGR_I2SSRC_EXTCLK	    	((u32)0x00800000)

#define 	RCC_CFGR_MCO1PRE1		        ((u8)0x00)
#define 	RCC_CFGR_MCO1PRE2		        ((u8)0x04)
#define 	RCC_CFGR_MCO1PRE3		        ((u8)0x05)
#define 	RCC_CFGR_MCO1PRE4		        ((u8)0x06)
#define 	RCC_CFGR_MCO1PRE5		        ((u8)0x07)

#define 	RCC_CFGR_MCO2PRE1		        ((u8)0x00)
#define 	RCC_CFGR_MCO2PRE2		        ((u8)0x04)
#define 	RCC_CFGR_MCO2PRE3		        ((u8)0x05)
#define 	RCC_CFGR_MCO2PRE4		        ((u8)0x06)
#define 	RCC_CFGR_MCO2PRE5		        ((u8)0x07)

#define 	RCC_CFGR_MCO2_SYSCLK		    ((u32)0x00000000)
#define 	RCC_CFGR_MCO2_PLLI2S		    ((u32)0x40000000)
#define 	RCC_CFGR_MCO2_HSE		        ((u32)0x80000000)
#define 	RCC_CFGR_MCO2_PLL		        ((u32)0xC0000000)



/*___________________________ RCC_CIR register MASKS___________________________ */
#define 	RCC_CIR_LSI_RDYF		        ((u32)0x00000001)    /* read only "FLAG" */
#define 	RCC_CIR_LSE_RDYF		        ((u32)0x00000002)	 /* read only "FLAG" */
#define 	RCC_CIR_HSI_RDYF		        ((u32)0x00000004)	 /* read only "FLAG" */
#define 	RCC_CIR_HSE_RDYF		        ((u32)0x00000008)	 /* read only "FLAG" */
#define 	RCC_CIR_PLL_RDYF		        ((u32)0x00000010)	 /* read only "FLAG" */
#define 	RCC_CIR_PLLI2S_RDYF		        ((u32)0x00000020)	 /* read only "FLAG" */
#define 	RCC_CIR_CSSF			        ((u32)0x00000080)	 /* read only "FLAG" */

#define 	RCC_CIR_LSI_RDYIE		        ((u32)0x00000100)
#define 	RCC_CIR_LSE_RDYIE		        ((u32)0x00000200)
#define 	RCC_CIR_HSI_RDYIE		        ((u32)0x00000400)
#define 	RCC_CIR_HSE_RDYIE		        ((u32)0x00000800)
#define 	RCC_CIR_PLL_RDYIE		        ((u32)0x00001000)
#define 	RCC_CIR_PLLI2S_RDYIE	        ((u32)0x00002000)

#define 	RCC_CIR_LSI_RDYC		        ((u32)0x00010000)    /* Write only "FLAG CLEAR" */
#define 	RCC_CIR_LSE_RDYC		        ((u32)0x00020000)	 /* Write only "FLAG CLEAR" */
#define 	RCC_CIR_HSI_RDYC		        ((u32)0x00040000)	 /* Write only "FLAG CLEAR" */
#define 	RCC_CIR_HSE_RDYC		        ((u32)0x00080000)	 /* Write only "FLAG CLEAR" */
#define 	RCC_CIR_PLL_RDYC		        ((u32)0x00100000)	 /* Write only "FLAG CLEAR" */
#define 	RCC_CIR_PLLI2S_RDYC		        ((u32)0x00200000)	 /* Write only "FLAG CLEAR" */
#define 	RCC_CIR_CSSC			        ((u32)0x00800000)	 /* Write only "FLAG CLEAR" */


/*___________________________ RCC_AHB1RSTR register MASKS___________________________ */
#define 	RCC_AHB1RSTR_GPIOA_RST		    ((u32)0x00000001)
#define 	RCC_AHB1RSTR_GPIOB_RST		    ((u32)0x00000002)
#define 	RCC_AHB1RSTR_GPIOC_RST		    ((u32)0x00000004)
#define 	RCC_AHB1RSTR_GPIOD_RST		    ((u32)0x00000008)
#define 	RCC_AHB1RSTR_GPIOE_RST		    ((u32)0x00000010)
#define 	RCC_AHB1RSTR_GPIOH_RST		    ((u32)0x00000080)

#define 	RCC_AHB1RSTR_CRC_RST		    ((u32)0x00001000)

#define 	RCC_AHB1RSTR_DMA1_RST		    ((u32)0x00200000)
#define 	RCC_AHB1RSTR_DMA2_RST		    ((u32)0x00400000)


/*___________________________ RCC_AHB2RSTR register MASKS___________________________ */
#define 	RCC_AHB2RSTR_OTGFS_RST		    ((u32)0x00000080)



/*___________________________ RCC_APB1RSTR register MASKS___________________________ */
#define     RCC_APB1RSTR_TIM2_RST			((u32)0x00000001)
#define     RCC_APB1RSTR_TIM3_RST			((u32)0x00000002)
#define     RCC_APB1RSTR_TIM4_RST			((u32)0x00000004)
#define     RCC_APB1RSTR_TIM5_RST			((u32)0x00000008)

#define 	RCC_APB1RSTR_WWDG_RST			((u32)0x00000800)

#define 	RCC_APB1RSTR_SPI2_RST			((u32)0x00004000)
#define 	RCC_APB1RSTR_SPI3_RST			((u32)0x00008000)

#define 	RCC_APB1RSTR_USART2_RST			((u32)0x00020000)

#define     RCC_APB1RSTR_I2C1_RST           ((u32)0x00200000)
#define     RCC_APB1RSTR_I2C2_RST           ((u32)0x00400000)
#define     RCC_APB1RSTR_I2C3_RST           ((u32)0x00800000)

#define 	RCC_APB1RSTR_PWR_RST			((u32)0x10000000)



/*___________________________ RCC_APB2RSTR register MASKS___________________________ */
#define 	RCC_APB2RSTR_TIM1_RST			((u32)0x00000001)

#define 	RCC_APB2RSTR_USART1_RST			((u32)0x00000010)
#define 	RCC_APB2RSTR_USART6_RST			((u32)0x00000020)

#define 	RCC_APB2RSTR_ADC1_RST			((u32)0x00000100)

#define 	RCC_APB2RSTR_SDIO_RST			((u32)0x00000800)

#define 	RCC_APB2RSTR_SPI1_RST			((u32)0x00001000)
#define 	RCC_APB2RSTR_SPI4_RST			((u32)0x00002000)

#define 	RCC_APB2RSTR_SYSCFG_RST			((u32)0x00004000)

#define 	RCC_APB2RSTR_TIM9_RST			((u32)0x00010000)
#define 	RCC_APB2RSTR_TIM10_RST			((u32)0x00020000)
#define 	RCC_APB2RSTR_TIM11_RST			((u32)0x00040000)



/*___________________________ RCC_AHB1ENR register MASKS___________________________ */
#define     RCC_AHB1ENR_GPIOA_EN		    ((u32)0x00000001)
#define     RCC_AHB1ENR_GPIOB_EN            ((u32)0x00000002)
#define     RCC_AHB1ENR_GPIOC_EN            ((u32)0x00000004)
#define     RCC_AHB1ENR_GPIOD_EN            ((u32)0x00000008)
#define     RCC_AHB1ENR_GPIOE_EN            ((u32)0x00000010)
#define     RCC_AHB1ENR_GPIOH_EN            ((u32)0x00000080)

#define     RCC_AHB1ENR_CRC_EN              ((u32)0x00001000)

#define     RCC_AHB1ENR_DMA1_EN             ((u32)0x00200000)
#define     RCC_AHB1ENR_DMA2_EN             ((u32)0x00400000)



/*___________________________ RCC_AHB2ENR register MASKS___________________________ */
#define 	RCC_AHB2ENR_OTGFS_EN			((u32)0x00000080)



/*___________________________ RCC_APB1ENR register MASKS___________________________ */
#define     RCC_APB1ENR_TIM2_EN			    ((u32)0x00000001)
#define     RCC_APB1ENR_TIM3_EN			    ((u32)0x00000002)
#define     RCC_APB1ENR_TIM4_EN			    ((u32)0x00000004)
#define     RCC_APB1ENR_TIM5_EN			    ((u32)0x00000008)

#define 	RCC_APB1ENR_WWDG_EN			    ((u32)0x00000800)

#define 	RCC_APB1ENR_SPI2_EN			    ((u32)0x00004000)
#define 	RCC_APB1ENR_SPI3_EN			    ((u32)0x00008000)

#define 	RCC_APB1ENR_USART2_EN			((u32)0x00020000)

#define     RCC_APB1ENR_I2C1_EN             ((u32)0x00200000)
#define     RCC_APB1ENR_I2C2_EN             ((u32)0x00400000)
#define     RCC_APB1ENR_I2C3_EN             ((u32)0x00800000)

#define 	RCC_APB1ENR_PWR_EN				((u32)0x10000000)



/*___________________________ RCC_APB2ENR register MASKS___________________________ */
#define 	RCC_APB2ENR_TIM1_EN  			((u32)0x00000001)

#define 	RCC_APB2ENR_USART1_EN			((u32)0x00000010)
#define 	RCC_APB2ENR_USART6_EN			((u32)0x00000020)

#define 	RCC_APB2ENR_ADC1_EN 			((u32)0x00000100)

#define 	RCC_APB2ENR_SDIO_EN 			((u32)0x00000800)

#define 	RCC_APB2ENR_SPI1_EN 			((u32)0x00001000)
#define 	RCC_APB2ENR_SPI4_EN 			((u32)0x00002000)

#define 	RCC_APB2ENR_SYSCFG_EN			((u32)0x00004000)

#define 	RCC_APB2ENR_TIM9_EN 			((u32)0x00010000)
#define 	RCC_APB2ENR_TIM10_EN			((u32)0x00020000)
#define 	RCC_APB2ENR_TIM11_EN			((u32)0x00040000)



/*___________________________ RCC_AHB1LPENR register MASKS___________________________ */
#define     RCC_AHB1LPENR_GPIOA_LPEN		((u32)0x00000001)
#define     RCC_AHB1LPENR_GPIOB_LPEN        ((u32)0x00000002)
#define     RCC_AHB1LPENR_GPIOC_LPEN        ((u32)0x00000004)
#define     RCC_AHB1LPENR_GPIOD_LPEN        ((u32)0x00000008)
#define     RCC_AHB1LPENR_GPIOE_LPEN        ((u32)0x00000010)
#define     RCC_AHB1LPENR_GPIOH_LPEN        ((u32)0x00000080)

#define     RCC_AHB1LPENR_CRC_LPEN          ((u32)0x00001000)
#define 	RCC_AHB1LPENR_FLITF_LPEN	    ((u32)0x00008000)

#define 	RCC_AHB1LPENR_SRAM1_LPEN	    ((u32)0x00010000)

#define     RCC_AHB1LPENR_DMA1_LPEN         ((u32)0x00200000)
#define     RCC_AHB1LPENR_DMA2_LPEN         ((u32)0x00400000)



/*___________________________ RCC_AHB2LPENR register MASKS___________________________ */
#define 	RCC_AHB2LPENR_OTGFS_LPEN		((u32)0x00000080)



/*___________________________ RCC_APB1LPENR register MASKS___________________________ */
#define     RCC_APB1LPENR_TIM2_LPEN			((u32)0x00000001)
#define     RCC_APB1LPENR_TIM3_LPEN			((u32)0x00000002)
#define     RCC_APB1LPENR_TIM4_LPEN			((u32)0x00000004)
#define     RCC_APB1LPENR_TIM5_LPEN			((u32)0x00000008)

#define 	RCC_APB1LPENR_WWDG_LPEN			((u32)0x00000800)

#define 	RCC_APB1LPENR_SPI2_LPEN			((u32)0x00004000)
#define 	RCC_APB1LPENR_SPI3_LPEN			((u32)0x00008000)

#define 	RCC_APB1LPENR_USART2_LPEN		((u32)0x00020000)

#define     RCC_APB1LPENR_I2C1_LPEN         ((u32)0x00200000)
#define     RCC_APB1LPENR_I2C2_LPEN         ((u32)0x00400000)
#define     RCC_APB1LPENR_I2C3_LPEN         ((u32)0x00800000)

#define 	RCC_APB1LPENR_PWR_LPEN			((u32)0x10000000)



/*___________________________ RCC_APB2LPENR register MASKS___________________________ */
#define 	RCC_APB2LPENR_TIM1_LPEN  	    ((u32)0x00000001)

#define 	RCC_APB2LPENR_USART1_LPEN	    ((u32)0x00000010)
#define 	RCC_APB2LPENR_USART6_LPEN	    ((u32)0x00000020)

#define 	RCC_APB2LPENR_ADC1_LPEN 	    ((u32)0x00000100)

#define 	RCC_APB2LPENR_SDIO_LPEN 	    ((u32)0x00000800)

#define 	RCC_APB2LPENR_SPI1_LPEN 	    ((u32)0x00001000)
#define 	RCC_APB2LPENR_SPI4_LPEN 	    ((u32)0x00002000)

#define 	RCC_APB2LPENR_SYSCFG_LPEN	    ((u32)0x00004000)

#define 	RCC_APB2LPENR_TIM9_LPEN 	    ((u32)0x00010000)
#define 	RCC_APB2LPENR_TIM10_LPEN	    ((u32)0x00020000)
#define 	RCC_APB2LPENR_TIM11_LPEN	    ((u32)0x00040000)



/*___________________________ RCC_BDCR register MASKS___________________________ */
#define 	RCC_BDCR_LSE_ON					((u32)0x00000001)
#define 	RCC_BDCR_LSE_RDY				((u32)0x00000002)     /* read only "FLAG" */
#define 	RCC_BDCR_LSE_BYB				((u32)0x00000004)

#define 	RCC_BDCR_RTC_NOCLK				((u32)0x00000000)
#define 	RCC_BDCR_RTC_LSE				((u32)0x00000100)
#define 	RCC_BDCR_RTC_LSI				((u32)0x00000200)
#define 	RCC_BDCR_RTC_HSE				((u32)0x00000300)

#define 	RCC_BDCR_RTC_EN				    ((u32)0x00008000)
#define 	RCC_BDCR_BDRST				    ((u32)0x00010000)



/*___________________________ RCC_CSR register MASKS___________________________ */
#define 	RCC_CSR_LSI_ON				    ((u32)0x00000001)
#define 	RCC_CSR_LSI_RDY				    ((u32)0x00000002)

#define 	RCC_CSR_RMVF				    ((u32)0x01000000)

#define 	RCC_CSR_BOR_RSTF			    ((u32)0x02000000)	 /* read only "FLAG" */
#define 	RCC_CSR_PIN_RSTF			    ((u32)0x04000000)	 /* read only "FLAG" */
#define 	RCC_CSR_POR_RSTF			    ((u32)0x08000000)	 /* read only "FLAG" */
#define 	RCC_CSR_SFT_RSTF			    ((u32)0x10000000)	 /* read only "FLAG" */
#define 	RCC_CSR_IWDG_RSTF			    ((u32)0x20000000)	 /* read only "FLAG" */
#define 	RCC_CSR_WWDG_RSTF			    ((u32)0x40000000)	 /* read only "FLAG" */
#define 	RCC_CSR_LPWR_RSTF			    ((u32)0x80000000)	 /* read only "FLAG" */



/*___________________________ RCC_SSCGR register MASKS___________________________ */
#define 	RCC_SSCGR_CENTER_SPREAD			((u32)0x00000000)
#define 	RCC_SSCGR_DOWN_SPREAD			((u32)0x40000000)

#define 	RCC_SSCGR_SSCG_EN				((u32)0x80000000)



/*___________________________ RCC_DCKCFGR register MASKS___________________________ */
#define 	RCC_DCKCFGR_TIMPRE			    ((u32)0x01000000)



/*__________________________________________________________________typedefs & function prototypes_______________________________________________________________________________________*/
typedef enum 
{
	RCC_enuOk,
	RCC_enuHsiClkRdy,
	RCC_enuHseClkRdy,
	RCC_enuPllClkRdy,
	RCC_enuLsiClkRdy,
	RCC_enuLseClkRdy,
	RCC_enuErrorClkNotRdy,
	RCC_enuErrorPeripheral,
	RCC_enuErrorWDGEnabled,
	RCC_enuErrorWDGEnabledLP,
	RCC_enuErrorClock,
	RCC_enuErrorContrlStatus,
	RCC_enuErrorSelectedSysClk,
	RCC_enuErrorNullPointer,
	RCC_enuErrorPLLOn,
	RCC_enuErrorPrescalerHseON,
	RCC_enuErrorPrescalerLseON,
	RCC_enuErrorRtcPrescaler,
	RCC_enuErrorMFactor,
	RCC_enuErrorNFactor,
	RCC_enuErrorPLLP,
	RCC_enuErrorPLLQ,
	RCC_enuErrorPLLSRC,
	RCC_enuErrorBus,
	RCC_enuErrorTimedOut,
	RCC_enuErrorBusPrescaler,
	RCC_enuErrorPinPrescaler,
	RCC_enuErrorSelectedPllClk

}RccEnuSysClkStat_t;

RccEnuSysClkStat_t	 		Rcc_tenuSelectSysClk 		    (u8 Copy_u8SysClkType);

RccEnuSysClkStat_t	  		Rcc_tenuClkControl  			(u8 Copy_u8Clk, u8 Copy_u8State);

RccEnuSysClkStat_t			Rcc_tenuGetClkStatus 	        (u8 Copy_u8Clk);

RccEnuSysClkStat_t	  		Rcc_tenuControlPeripheral 	    (u8 Copy_u8PeriBusReg ,u32 Copy_u32Peripheral, u8 Copy_u8State);

RccEnuSysClkStat_t	  		Rcc_tenuConfigPll	    	    (u8 Copy_u8PllM, u16 Copy_u16PllN, u8 Copy_u8PllP, u8 Copy_u8PllQ, u32 Copy_u32PllSrc);

RccEnuSysClkStat_t	 		Rcc_tenuConfigBusPinPrescaler	(u8 Copy_u8AHBPrescaler, u8 Copy_u8APB1Prescaler, u8 Copy_u8APB2Prescaler,
		                                                     u8 Copy_u8MCO1Prescaler,
		                                                     u8 Copy_u8MCO2Prescaler);

RccEnuSysClkStat_t	 		Rcc_tenuSetRtcPrescaler      (u8 Copy_u8RTCPrescaler);

/*  handlers */
void NMI_Handler (void);

/*__________________________________________________________________Section configuration_______________________________________________________________________________________*/

/* ------------------------PLL_CONFIGURATION PARAMETERS---------------------------*/
#define 	RCC_PLLCFGR_PLLM_FACTOR 						RCC_PLLCFGR_PLLM10
#define 	RCC_PLLCFGR_PLLN_FACTOR 						RCC_PLLCFGR_PLLN200
#define 	RCC_PLLCFGR_PLLP_FACTOR							RCC_PLLCFGR_PLLP4
#define 	RCC_PLLCFGR_PLLSRC_CLK							RCC_PLLCFGR_PLLSRC_HSE
#define 	RCC_PLLCFGR_PLLQ_FACTOR							RCC_PLLCFGR_PLLQ15
/*--------------------------------------------------------------------------------*/

/* ------------------------PRESCALER_CONFIGURATION PARAMETERS---------------------------*/
#define 	RCC_CFGR_AHB_PRESCALER 							RCC_CFGR_HPRE1_0
#define 	RCC_CFGR_APB1_PRESCALER 						RCC_CFGR_PPRE1_1_0
#define 	RCC_CFGR_APB2_PRESCALER							RCC_CFGR_PPRE2_1_0

#define 	RCC_CFGR_MCO1_PRESCALER							RCC_CFGR_MCO1PRE1
#define 	RCC_CFGR_MCO2_PRESCALER							RCC_CFGR_MCO2PRE1

#define 	RCC_CFGR_RTC_PRESCALER							RCC_CFGR_RTCPRE_HSE1_0
/*--------------------------------------------------------------------------------*/

#endif
