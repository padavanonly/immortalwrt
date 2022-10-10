/* SPDX-License-Identifier: GPL-2.0
 *
 * Copyright (c) 2021 MediaTek Inc.
 * Author: Henry Yen <henry.yen@mediatek.com>
 */

#ifndef NF_HNAT_SFQ_H
#define NF_HNAT_SFQ_H

/* QDMA SFQ */
#define MTK_VQG_NUM		8
#define MTK_PER_GRP_VQ_NUM	128
#define MTK_SFQ_OFFSET		0x1A80
#define MTK_VQTX_GLO		MTK_SFQ_OFFSET
#define MTK_VQTX_INVLD_PTR	(MTK_SFQ_OFFSET + 0x0C)
#define MTK_VQTX_NUM		(MTK_SFQ_OFFSET + 0x10)
#define MTK_VQTX_SCH		(MTK_SFQ_OFFSET + 0x18)
#define MTK_VQTX_HASH_CFG	(MTK_SFQ_OFFSET + 0x20)
#define MTK_VQTX_HASH_SD	(MTK_SFQ_OFFSET + 0x24)
#define MTK_VQTX_VLD_CFG	(MTK_SFQ_OFFSET + 0x30)
#define MTK_VQTX_MIB_IF		(MTK_SFQ_OFFSET + 0x3C)
#define MTK_VQTX_MIB_PCNT	(MTK_SFQ_OFFSET + 0x40)
#define MTK_VQTX_MIB_BCNT0	(MTK_SFQ_OFFSET + 0x44)
#define MTK_VQTX_MIB_BCNT1	(MTK_SFQ_OFFSET + 0x48)
#define MTK_VQTX_MIB_DPCNT	(MTK_SFQ_OFFSET + 0x4C)
#define MTK_QTX_MIB_PCNT	(MTK_SFQ_OFFSET + 0x50)
#define MTK_QTX_MIB_DPCNT	(MTK_SFQ_OFFSET + 0x54)
#define MTK_VQTX_0_3_BIND_QID	(MTK_SFQ_OFFSET + 0x140)
#define MTK_VQTX_4_7_BIND_QID	(MTK_SFQ_OFFSET + 0x144)
#define MTK_VQTX_TB_BASE(x)	(0x1980 + (x) * 0x4)

/* TX Virtual Queue Global Configuration Register*/
#define VQTB_MIB_EN		BIT(17)

/* TX Virtual Queue Hash Configuration Register*/
#define HASH_PTB_MODE_EN_0	BIT(24)
#define HASH_PTB_MODE_EN_1	BIT(25)
#define HASH_PTB_MODE_EN_2	BIT(26)
#define HASH_PTB_MODE_EN_3	BIT(27)
#define HASH_PTB_PRD		0x2710

/* TX Virtual Queue Valid Configuration Register*/
#define VQTX_VLD_STRG_0		(0 << 0)
#define VQTX_VLD_STRG_1		(2 << 4)
#define VQTX_VLD_STRG_2		(4 << 8)
#define VQTX_VLD_STRG_3		(6 << 12)
#define VQTX_VLD_STRG_4		(8 << 16)
#define VQTX_VLD_STRG_5		(10 << 20)
#define VQTX_VLD_STRG_6		(12 << 24)
#define VQTX_VLD_STRG_7		(14 << 28)

/* TX Virtual Queue Hash Seed Register*/
#define HASH_SD			0xD


/* Flow Control Threshold Register*/
#define HW_DROP_EN		BIT(16)
#define HW_DROP_FFA		BIT(17)
#define HW_DROP_FSTVQ		BIT(19)
#define HW_DROP_MODE		BIT(20)
#define SW_DROP_EN		BIT(24)
#define SW_DROP_FFA		BIT(25)
#define SW_DROP_FSTVQ		BIT(27)
#define SW_DROP_MODE		BIT(28)
#define RING_TH			(4 << 0)
#define FREE_TH			(4 << 4)
#define SHARE_HW_TH		(4 << 8)
#define SHARE_SW_TH		(4 << 12)
#define HW_DROP_FSTVQ_MODE	(2 << 22)
#define	SW_DROP_FSTVQ_MODE	(2 << 30)

/* Number of TX Virtual Queue Configuration Register*/
#define VQTX_NUM_0		(3 << 0)
#define VQTX_NUM_1		(3 << 4)
#define VQTX_NUM_2		(3 << 8)
#define VQTX_NUM_3		(3 << 12)
#define VQTX_NUM_4		(3 << 16)
#define VQTX_NUM_5		(3 << 20)
#define VQTX_NUM_6		(3 << 24)
#define VQTX_NUM_7		(3 << 28)

/* QDMA Virtual Queue Group #0~7 to Physical Queue Binding Register*/
#define MTK_PQ0			0
#define MTK_PQ1			1
#define MTK_PQ2			15
#define MTK_PQ3			16
#define MTK_PQ4			30
#define MTK_PQ5			31
#define MTK_PQ6			43
#define MTK_PQ7			63
#define VQTX_0_BIND_QID(x)	((x) << 0)
#define VQTX_1_BIND_QID(x)	((x) << 8)
#define VQTX_2_BIND_QID(x)	((x) << 16)
#define VQTX_3_BIND_QID(x)	((x) << 24)
#define VQTX_4_BIND_QID(x)	((x) << 0)
#define VQTX_5_BIND_QID(x)	((x) << 8)
#define VQTX_6_BIND_QID(x)	((x) << 16)
#define VQTX_7_BIND_QID(x)	((x) << 24)

/*--------------------------------------------------------------------------*/
/* SFQ Table Definition*/
/*--------------------------------------------------------------------------*/

struct mtk_sfq_info1 {
	u32	vqhptr;
};

struct mtk_sfq_info2 {
	u32	vqtptr;
};

struct mtk_sfq_info3 {
	u32	que_depth : 16;
	u32	deficit_cnt : 16;
};

struct mtk_sfq_info4 {
	u32	resv;
};

struct mtk_sfq_info5 {
	u32	pkt_cnt;
};

struct mtk_sfq_info6 {
	u32	byte_cnt;
};

struct mtk_sfq_info7 {
	u32	byte_cnt;
};

struct mtk_sfq_info8 {
	u32	resv;
};

struct mtk_sfq_table {
	struct mtk_sfq_info1	sfq_info1;
	struct mtk_sfq_info2	sfq_info2;
	struct mtk_sfq_info3	sfq_info3;
	struct mtk_sfq_info4	sfq_info4;
	struct mtk_sfq_info5	sfq_info5;
	struct mtk_sfq_info6	sfq_info6;
	struct mtk_sfq_info7	sfq_info7;
	struct mtk_sfq_info8	sfq_info8;
};

#if defined(CONFIG_NET_MEDIATEK_HW_QOS)
int hnat_sfq_init(void);
int hnat_sfq_deinit(void);
extern int (*hnat_sfq_init_hook)(void);
#endif
#endif
