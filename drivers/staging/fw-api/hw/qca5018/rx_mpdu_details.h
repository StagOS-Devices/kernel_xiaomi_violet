/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _RX_MPDU_DETAILS_H_
#define _RX_MPDU_DETAILS_H_
#if !defined(__ASSEMBLER__)
#endif

#include "buffer_addr_info.h"
#include "rx_mpdu_desc_info.h"

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0-1	struct buffer_addr_info msdu_link_desc_addr_info;
//	2-3	struct rx_mpdu_desc_info rx_mpdu_desc_info_details;
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_MPDU_DETAILS 4

struct rx_mpdu_details {
    struct            buffer_addr_info                       msdu_link_desc_addr_info;
    struct            rx_mpdu_desc_info                       rx_mpdu_desc_info_details;
};

/*

struct buffer_addr_info msdu_link_desc_addr_info
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			Details of the physical address of the MSDU link
			descriptor that contains pointers to MSDUs related to this
			MPDU

struct rx_mpdu_desc_info rx_mpdu_desc_info_details
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			General information related to the MPDU that should be
*/


 /* EXTERNAL REFERENCE : struct buffer_addr_info msdu_link_desc_addr_info */ 


/* Description		RX_MPDU_DETAILS_0_MSDU_LINK_DESC_ADDR_INFO_BUFFER_ADDR_31_0
			
			Address (lower 32 bits) of the MSDU buffer OR
			MSDU_EXTENSION descriptor OR Link Descriptor
			
			
			
			In case of 'NULL' pointer, this field is set to 0
			
			<legal all>
*/
#define RX_MPDU_DETAILS_0_MSDU_LINK_DESC_ADDR_INFO_BUFFER_ADDR_31_0_OFFSET 0x00000000
#define RX_MPDU_DETAILS_0_MSDU_LINK_DESC_ADDR_INFO_BUFFER_ADDR_31_0_LSB 0
#define RX_MPDU_DETAILS_0_MSDU_LINK_DESC_ADDR_INFO_BUFFER_ADDR_31_0_MASK 0xffffffff

/* Description		RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_BUFFER_ADDR_39_32
			
			Address (upper 8 bits) of the MSDU buffer OR
			MSDU_EXTENSION descriptor OR Link Descriptor
			
			
			
			In case of 'NULL' pointer, this field is set to 0
			
			<legal all>
*/
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_BUFFER_ADDR_39_32_OFFSET 0x00000004
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_BUFFER_ADDR_39_32_LSB 0
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_BUFFER_ADDR_39_32_MASK 0x000000ff

/* Description		RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_RETURN_BUFFER_MANAGER
			
			Consumer: WBM
			
			Producer: SW/FW
			
			
			
			In case of 'NULL' pointer, this field is set to 0
			
			
			
			Indicates to which buffer manager the buffer OR
			MSDU_EXTENSION descriptor OR link descriptor that is being
			pointed to shall be returned after the frame has been
			processed. It is used by WBM for routing purposes.
			
			
			
			<enum 0 WBM_IDLE_BUF_LIST> This buffer shall be returned
			to the WMB buffer idle list
			
			<enum 1 WBM_IDLE_DESC_LIST> This buffer shall be
			returned to the WMB idle link descriptor idle list
			
			<enum 2 FW_BM> This buffer shall be returned to the FW
			
			<enum 3 SW0_BM> This buffer shall be returned to the SW,
			ring 0
			
			<enum 4 SW1_BM> This buffer shall be returned to the SW,
			ring 1
			
			<enum 5 SW2_BM> This buffer shall be returned to the SW,
			ring 2
			
			<enum 6 SW3_BM> This buffer shall be returned to the SW,
			ring 3
			
			<enum 7 SW4_BM> This buffer shall be returned to the SW,
			ring 4
			
			
			
			<legal all>
*/
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_RETURN_BUFFER_MANAGER_OFFSET 0x00000004
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_RETURN_BUFFER_MANAGER_LSB 8
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_RETURN_BUFFER_MANAGER_MASK 0x00000700

/* Description		RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_SW_BUFFER_COOKIE
			
			Cookie field exclusively used by SW. 
			
			
			
			In case of 'NULL' pointer, this field is set to 0
			
			
			
			HW ignores the contents, accept that it passes the
			programmed value on to other descriptors together with the
			physical address 
			
			
			
			Field can be used by SW to for example associate the
			buffers physical address with the virtual address
			
			The bit definitions as used by SW are within SW HLD
			specification
			
			
			
			NOTE1:
			
			The three most significant bits can have a special
			meaning in case this struct is embedded in a TX_MPDU_DETAILS
			STRUCT, and field transmit_bw_restriction is set
			
			
			
			In case of NON punctured transmission:
			
			Sw_buffer_cookie[20:19] = 2'b00: 20 MHz TX only
			
			Sw_buffer_cookie[20:19] = 2'b01: 40 MHz TX only
			
			Sw_buffer_cookie[20:19] = 2'b10: 80 MHz TX only
			
			Sw_buffer_cookie[20:19] = 2'b11: 160 MHz TX only
			
			
			
			In case of punctured transmission:
			
			Sw_buffer_cookie[20:18] = 3'b000: pattern 0 only
			
			Sw_buffer_cookie[20:18] = 3'b001: pattern 1 only
			
			Sw_buffer_cookie[20:18] = 3'b010: pattern 2 only
			
			Sw_buffer_cookie[20:18] = 3'b011: pattern 3 only
			
			Sw_buffer_cookie[20:18] = 3'b100: pattern 4 only
			
			Sw_buffer_cookie[20:18] = 3'b101: pattern 5 only
			
			Sw_buffer_cookie[20:18] = 3'b110: pattern 6 only
			
			Sw_buffer_cookie[20:18] = 3'b111: pattern 7 only
			
			
			
			Note: a punctured transmission is indicated by the
			presence of TLV TX_PUNCTURE_SETUP embedded in the scheduler
			TLV
			
			
			
			NOTE 2:The five most significant bits can have a special
			meaning in case this struct is embedded in an
			RX_MSDU_DETAILS STRUCT, and Maple/Spruce Rx DMA is
			configured for passing on the additional info
			from??'RX_MPDU_INFO' structure in 'RX_MPDU_START' TLV
			(FR56821). This is not supported in HastingsPrime, Pine or
			Moselle. 
			
			
			
			Sw_buffer_cookie[20:17]: Tid: The TID field in the QoS
			control field
			
			
			
			Sw_buffer_cookie[16]: Mpdu_qos_control_valid: This field
			indicates MPDUs with a QoS control field.
			
			
			
			
			
			<legal all>
*/
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_SW_BUFFER_COOKIE_OFFSET 0x00000004
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_SW_BUFFER_COOKIE_LSB 11
#define RX_MPDU_DETAILS_1_MSDU_LINK_DESC_ADDR_INFO_SW_BUFFER_COOKIE_MASK 0xfffff800

 /* EXTERNAL REFERENCE : struct rx_mpdu_desc_info rx_mpdu_desc_info_details */ 


/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MSDU_COUNT
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			The number of MSDUs within the MPDU 
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MSDU_COUNT_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MSDU_COUNT_LSB   0
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MSDU_COUNT_MASK  0x000000ff

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MPDU_SEQUENCE_NUMBER
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			The field can have two different meanings based on the
			setting of field 'BAR_frame':
			
			
			
			'BAR_frame' is NOT set:
			
			The MPDU sequence number of the received frame.
			
			
			
			'BAR_frame' is set.
			
			The MPDU Start sequence number from the BAR frame
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MPDU_SEQUENCE_NUMBER_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MPDU_SEQUENCE_NUMBER_LSB 8
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MPDU_SEQUENCE_NUMBER_MASK 0x000fff00

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_FRAGMENT_FLAG
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			When set, this MPDU is a fragment and REO should forward
			this fragment MPDU to the REO destination ring without any
			reorder checks, pn checks or bitmap update. This implies
			that REO is forwarding the pointer to the MSDU link
			descriptor. The destination ring is coming from a
			programmable register setting in REO
			
			
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_FRAGMENT_FLAG_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_FRAGMENT_FLAG_LSB 20
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_FRAGMENT_FLAG_MASK 0x00100000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MPDU_RETRY_BIT
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			The retry bit setting from the MPDU header of the
			received frame
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MPDU_RETRY_BIT_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MPDU_RETRY_BIT_LSB 21
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MPDU_RETRY_BIT_MASK 0x00200000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_AMPDU_FLAG
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			When set, the MPDU was received as part of an A-MPDU.
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_AMPDU_FLAG_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_AMPDU_FLAG_LSB   22
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_AMPDU_FLAG_MASK  0x00400000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_BAR_FRAME
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			When set, the received frame is a BAR frame. After
			processing, this frame shall be pushed to SW or deleted.
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_BAR_FRAME_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_BAR_FRAME_LSB    23
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_BAR_FRAME_MASK   0x00800000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_PN_FIELDS_CONTAIN_VALID_INFO
			
			Consumer: REO/SW/FW
			
			Producer: RXDMA
			
			
			
			Copied here by RXDMA from RX_MPDU_END
			
			When not set, REO will Not perform a PN sequence number
			check
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_PN_FIELDS_CONTAIN_VALID_INFO_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_PN_FIELDS_CONTAIN_VALID_INFO_LSB 24
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_PN_FIELDS_CONTAIN_VALID_INFO_MASK 0x01000000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_SA_IS_VALID
			
			When set, OLE found a valid SA entry for all MSDUs in
			this MPDU
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_SA_IS_VALID_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_SA_IS_VALID_LSB  25
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_SA_IS_VALID_MASK 0x02000000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_SA_IDX_TIMEOUT
			
			When set, at least 1 MSDU within the MPDU has an
			unsuccessful MAC source address search due to the expiration
			of the search timer.
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_SA_IDX_TIMEOUT_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_SA_IDX_TIMEOUT_LSB 26
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_SA_IDX_TIMEOUT_MASK 0x04000000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IS_VALID
			
			When set, OLE found a valid DA entry for all MSDUs in
			this MPDU
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IS_VALID_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IS_VALID_LSB  27
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IS_VALID_MASK 0x08000000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IS_MCBC
			
			Field Only valid if da_is_valid is set
			
			
			
			When set, at least one of the DA addresses is a
			Multicast or Broadcast address.
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IS_MCBC_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IS_MCBC_LSB   28
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IS_MCBC_MASK  0x10000000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IDX_TIMEOUT
			
			When set, at least 1 MSDU within the MPDU has an
			unsuccessful MAC destination address search due to the
			expiration of the search timer.
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IDX_TIMEOUT_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IDX_TIMEOUT_LSB 29
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_DA_IDX_TIMEOUT_MASK 0x20000000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_RAW_MPDU
			
			Field only valid when first_msdu_in_mpdu_flag is set.
			
			
			
			When set, the contents in the MSDU buffer contains a
			'RAW' MPDU. This 'RAW' MPDU might be spread out over
			multiple MSDU buffers.
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_RAW_MPDU_OFFSET  0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_RAW_MPDU_LSB     30
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_RAW_MPDU_MASK    0x40000000

/* Description		RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MORE_FRAGMENT_FLAG
			
			The More Fragment bit setting from the MPDU header of
			the received frame
			
			
			
			<legal all>
*/
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MORE_FRAGMENT_FLAG_OFFSET 0x00000008
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MORE_FRAGMENT_FLAG_LSB 31
#define RX_MPDU_DETAILS_2_RX_MPDU_DESC_INFO_DETAILS_MORE_FRAGMENT_FLAG_MASK 0x80000000

/* Description		RX_MPDU_DETAILS_3_RX_MPDU_DESC_INFO_DETAILS_PEER_META_DATA
			
			Meta data that SW has programmed in the Peer table entry
			of the transmitting STA.
			
			<legal all>
*/
#define RX_MPDU_DETAILS_3_RX_MPDU_DESC_INFO_DETAILS_PEER_META_DATA_OFFSET 0x0000000c
#define RX_MPDU_DETAILS_3_RX_MPDU_DESC_INFO_DETAILS_PEER_META_DATA_LSB 0
#define RX_MPDU_DETAILS_3_RX_MPDU_DESC_INFO_DETAILS_PEER_META_DATA_MASK 0xffffffff


#endif // _RX_MPDU_DETAILS_H_
