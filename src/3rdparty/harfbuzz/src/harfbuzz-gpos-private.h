begin_unit
begin_comment
comment|/*  * Copyright (C) 1998-2004  David Turner and Werner Lemberg  * Copyright (C) 2006  Behdad Esfahbod  *  * This is part of HarfBuzz, an OpenType Layout engine library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HARFBUZZ_GPOS_PRIVATE_H
end_ifndef
begin_define
DECL|macro|HARFBUZZ_GPOS_PRIVATE_H
define|#
directive|define
name|HARFBUZZ_GPOS_PRIVATE_H
end_define
begin_include
include|#
directive|include
file|"harfbuzz-impl.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-stream-private.h"
end_include
begin_include
include|#
directive|include
file|"harfbuzz-gpos.h"
end_include
begin_macro
name|HB_BEGIN_HEADER
end_macro
begin_comment
comment|/* shared tables */
end_comment
begin_define
DECL|macro|VR_X_PLACEMENT_DEVICE
define|#
directive|define
name|VR_X_PLACEMENT_DEVICE
value|0
end_define
begin_define
DECL|macro|VR_Y_PLACEMENT_DEVICE
define|#
directive|define
name|VR_Y_PLACEMENT_DEVICE
value|1
end_define
begin_define
DECL|macro|VR_X_ADVANCE_DEVICE
define|#
directive|define
name|VR_X_ADVANCE_DEVICE
value|2
end_define
begin_define
DECL|macro|VR_Y_ADVANCE_DEVICE
define|#
directive|define
name|VR_Y_ADVANCE_DEVICE
value|3
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|HB_SUPPORT_MULTIPLE_MASTER
end_ifndef
begin_define
DECL|macro|HB_USE_FLEXIBLE_VALUE_RECORD
define|#
directive|define
name|HB_USE_FLEXIBLE_VALUE_RECORD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|HB_ValueRecord_
struct|struct
name|HB_ValueRecord_
block|{
DECL|member|XPlacement
name|HB_Short
name|XPlacement
decl_stmt|;
comment|/* horizontal adjustment for 					 placement                      */
DECL|member|YPlacement
name|HB_Short
name|YPlacement
decl_stmt|;
comment|/* vertical adjustment for 					 placement                      */
DECL|member|XAdvance
name|HB_Short
name|XAdvance
decl_stmt|;
comment|/* horizontal adjustment for 					 advance                        */
DECL|member|YAdvance
name|HB_Short
name|YAdvance
decl_stmt|;
comment|/* vertical adjustment for 					 advance                        */
DECL|member|DeviceTables
name|HB_Device
modifier|*
modifier|*
name|DeviceTables
decl_stmt|;
comment|/* device tables for placement 					 and advance                    */
ifdef|#
directive|ifdef
name|HB_SUPPORT_MULTIPLE_MASTER
DECL|member|XIdPlacement
name|HB_UShort
name|XIdPlacement
decl_stmt|;
comment|/* horizontal placement metric ID */
DECL|member|YIdPlacement
name|HB_UShort
name|YIdPlacement
decl_stmt|;
comment|/* vertical placement metric ID   */
DECL|member|XIdAdvance
name|HB_UShort
name|XIdAdvance
decl_stmt|;
comment|/* horizontal advance metric ID   */
DECL|member|YIdAdvance
name|HB_UShort
name|YIdAdvance
decl_stmt|;
comment|/* vertical advance metric ID     */
endif|#
directive|endif
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ValueRecord
typedef|typedef
name|struct
name|HB_ValueRecord_
name|HB_ValueRecord
typedef|;
end_typedef
begin_comment
comment|/* Mask values to scan the value format of the ValueRecord structure.  We always expand compressed ValueRecords of the font.              */
end_comment
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_DEVICE_TABLES
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_DEVICE_TABLES
value|0x00F0
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_X_PLACEMENT
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_X_PLACEMENT
value|0x0001
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_Y_PLACEMENT
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_Y_PLACEMENT
value|0x0002
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_X_ADVANCE
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_X_ADVANCE
value|0x0004
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_Y_ADVANCE
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_Y_ADVANCE
value|0x0008
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_X_PLACEMENT_DEVICE
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_X_PLACEMENT_DEVICE
value|0x0010
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_Y_PLACEMENT_DEVICE
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_Y_PLACEMENT_DEVICE
value|0x0020
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_X_ADVANCE_DEVICE
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_X_ADVANCE_DEVICE
value|0x0040
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_Y_ADVANCE_DEVICE
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_Y_ADVANCE_DEVICE
value|0x0080
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_X_ID_PLACEMENT
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_X_ID_PLACEMENT
value|0x0100
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_Y_ID_PLACEMENT
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_Y_ID_PLACEMENT
value|0x0200
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_X_ID_ADVANCE
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_X_ID_ADVANCE
value|0x0400
end_define
begin_define
DECL|macro|HB_GPOS_FORMAT_HAVE_Y_ID_ADVANCE
define|#
directive|define
name|HB_GPOS_FORMAT_HAVE_Y_ID_ADVANCE
value|0x0800
end_define
begin_struct
DECL|struct|HB_AnchorFormat1_
struct|struct
name|HB_AnchorFormat1_
block|{
DECL|member|XCoordinate
name|HB_Short
name|XCoordinate
decl_stmt|;
comment|/* horizontal value */
DECL|member|YCoordinate
name|HB_Short
name|YCoordinate
decl_stmt|;
comment|/* vertical value   */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_AnchorFormat1
typedef|typedef
name|struct
name|HB_AnchorFormat1_
name|HB_AnchorFormat1
typedef|;
end_typedef
begin_struct
DECL|struct|HB_AnchorFormat2_
struct|struct
name|HB_AnchorFormat2_
block|{
DECL|member|XCoordinate
name|HB_Short
name|XCoordinate
decl_stmt|;
comment|/* horizontal value             */
DECL|member|YCoordinate
name|HB_Short
name|YCoordinate
decl_stmt|;
comment|/* vertical value               */
DECL|member|AnchorPoint
name|HB_UShort
name|AnchorPoint
decl_stmt|;
comment|/* index to glyph contour point */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_AnchorFormat2
typedef|typedef
name|struct
name|HB_AnchorFormat2_
name|HB_AnchorFormat2
typedef|;
end_typedef
begin_define
DECL|macro|AF3_X_DEVICE_TABLE
define|#
directive|define
name|AF3_X_DEVICE_TABLE
value|0
end_define
begin_define
DECL|macro|AF3_Y_DEVICE_TABLE
define|#
directive|define
name|AF3_Y_DEVICE_TABLE
value|1
end_define
begin_struct
DECL|struct|HB_AnchorFormat3_
struct|struct
name|HB_AnchorFormat3_
block|{
DECL|member|XCoordinate
name|HB_Short
name|XCoordinate
decl_stmt|;
comment|/* horizontal value              */
DECL|member|YCoordinate
name|HB_Short
name|YCoordinate
decl_stmt|;
comment|/* vertical value                */
DECL|member|DeviceTables
name|HB_Device
modifier|*
modifier|*
name|DeviceTables
decl_stmt|;
comment|/* device tables for coordinates */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_AnchorFormat3
typedef|typedef
name|struct
name|HB_AnchorFormat3_
name|HB_AnchorFormat3
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|HB_SUPPORT_MULTIPLE_MASTER
end_ifdef
begin_struct
DECL|struct|HB_AnchorFormat4_
struct|struct
name|HB_AnchorFormat4_
block|{
DECL|member|XIdAnchor
name|HB_UShort
name|XIdAnchor
decl_stmt|;
comment|/* horizontal metric ID */
DECL|member|YIdAnchor
name|HB_UShort
name|YIdAnchor
decl_stmt|;
comment|/* vertical metric ID   */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_AnchorFormat4
typedef|typedef
name|struct
name|HB_AnchorFormat4_
name|HB_AnchorFormat4
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|HB_Anchor_
struct|struct
name|HB_Anchor_
block|{
DECL|member|PosFormat
name|HB_Byte
name|PosFormat
decl_stmt|;
comment|/* 1, 2, 3, or 4 -- 0 indicates 					 that there is no Anchor table */
union|union
block|{
DECL|member|af1
name|HB_AnchorFormat1
name|af1
decl_stmt|;
DECL|member|af2
name|HB_AnchorFormat2
name|af2
decl_stmt|;
DECL|member|af3
name|HB_AnchorFormat3
name|af3
decl_stmt|;
ifdef|#
directive|ifdef
name|HB_SUPPORT_MULTIPLE_MASTER
DECL|member|af4
name|HB_AnchorFormat4
name|af4
decl_stmt|;
endif|#
directive|endif
block|}
DECL|member|af
name|af
union|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_Anchor
typedef|typedef
name|struct
name|HB_Anchor_
name|HB_Anchor
typedef|;
end_typedef
begin_struct
DECL|struct|HB_MarkRecord_
struct|struct
name|HB_MarkRecord_
block|{
DECL|member|Class
name|HB_UShort
name|Class
decl_stmt|;
comment|/* mark class   */
DECL|member|MarkAnchor
name|HB_Anchor
name|MarkAnchor
decl_stmt|;
comment|/* anchor table */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_MarkRecord
typedef|typedef
name|struct
name|HB_MarkRecord_
name|HB_MarkRecord
typedef|;
end_typedef
begin_struct
DECL|struct|HB_MarkArray_
struct|struct
name|HB_MarkArray_
block|{
DECL|member|MarkCount
name|HB_UShort
name|MarkCount
decl_stmt|;
comment|/* number of MarkRecord tables */
DECL|member|MarkRecord
name|HB_MarkRecord
modifier|*
name|MarkRecord
decl_stmt|;
comment|/* array of MarkRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_MarkArray
typedef|typedef
name|struct
name|HB_MarkArray_
name|HB_MarkArray
typedef|;
end_typedef
begin_comment
comment|/* LookupType 1 */
end_comment
begin_struct
DECL|struct|HB_SinglePosFormat1_
struct|struct
name|HB_SinglePosFormat1_
block|{
DECL|member|Value
name|HB_ValueRecord
name|Value
decl_stmt|;
comment|/* ValueRecord for all covered 					 glyphs                      */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SinglePosFormat1
typedef|typedef
name|struct
name|HB_SinglePosFormat1_
name|HB_SinglePosFormat1
typedef|;
end_typedef
begin_struct
DECL|struct|HB_SinglePosFormat2_
struct|struct
name|HB_SinglePosFormat2_
block|{
DECL|member|ValueCount
name|HB_UShort
name|ValueCount
decl_stmt|;
comment|/* number of ValueRecord tables */
DECL|member|Value
name|HB_ValueRecord
modifier|*
name|Value
decl_stmt|;
comment|/* array of ValueRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SinglePosFormat2
typedef|typedef
name|struct
name|HB_SinglePosFormat2_
name|HB_SinglePosFormat2
typedef|;
end_typedef
begin_struct
DECL|struct|HB_SinglePos_
struct|struct
name|HB_SinglePos_
block|{
DECL|member|PosFormat
name|HB_Byte
name|PosFormat
decl_stmt|;
comment|/* 1 or 2         */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table */
DECL|member|ValueFormat
name|HB_UShort
name|ValueFormat
decl_stmt|;
comment|/* format of ValueRecord table */
union|union
block|{
DECL|member|spf1
name|HB_SinglePosFormat1
name|spf1
decl_stmt|;
DECL|member|spf2
name|HB_SinglePosFormat2
name|spf2
decl_stmt|;
block|}
DECL|member|spf
name|spf
union|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_SinglePos
typedef|typedef
name|struct
name|HB_SinglePos_
name|HB_SinglePos
typedef|;
end_typedef
begin_comment
comment|/* LookupType 2 */
end_comment
begin_struct
DECL|struct|HB_PairValueRecord_
struct|struct
name|HB_PairValueRecord_
block|{
DECL|member|SecondGlyph
name|HB_UShort
name|SecondGlyph
decl_stmt|;
comment|/* glyph ID for second glyph  */
DECL|member|Value1
name|HB_ValueRecord
name|Value1
decl_stmt|;
comment|/* pos. data for first glyph  */
DECL|member|Value2
name|HB_ValueRecord
name|Value2
decl_stmt|;
comment|/* pos. data for second glyph */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PairValueRecord
typedef|typedef
name|struct
name|HB_PairValueRecord_
name|HB_PairValueRecord
typedef|;
end_typedef
begin_struct
DECL|struct|HB_PairSet_
struct|struct
name|HB_PairSet_
block|{
DECL|member|PairValueCount
name|HB_UShort
name|PairValueCount
decl_stmt|;
comment|/* number of PairValueRecord tables */
DECL|member|PairValueRecord
name|HB_PairValueRecord
modifier|*
name|PairValueRecord
decl_stmt|;
comment|/* array of PairValueRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PairSet
typedef|typedef
name|struct
name|HB_PairSet_
name|HB_PairSet
typedef|;
end_typedef
begin_struct
DECL|struct|HB_PairPosFormat1_
struct|struct
name|HB_PairPosFormat1_
block|{
DECL|member|PairSetCount
name|HB_UShort
name|PairSetCount
decl_stmt|;
comment|/* number of PairSet tables    */
DECL|member|PairSet
name|HB_PairSet
modifier|*
name|PairSet
decl_stmt|;
comment|/* array of PairSet tables     */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PairPosFormat1
typedef|typedef
name|struct
name|HB_PairPosFormat1_
name|HB_PairPosFormat1
typedef|;
end_typedef
begin_struct
DECL|struct|HB_Class2Record_
struct|struct
name|HB_Class2Record_
block|{
DECL|member|Value1
name|HB_ValueRecord
name|Value1
decl_stmt|;
comment|/* pos. data for first glyph  */
DECL|member|Value2
name|HB_ValueRecord
name|Value2
decl_stmt|;
comment|/* pos. data for second glyph */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_Class2Record
typedef|typedef
name|struct
name|HB_Class2Record_
name|HB_Class2Record
typedef|;
end_typedef
begin_struct
DECL|struct|HB_Class1Record_
struct|struct
name|HB_Class1Record_
block|{
DECL|member|IsFlexible
name|hb_uint8
name|IsFlexible
decl_stmt|;
union|union
block|{
DECL|member|Class2Record
name|HB_Class2Record
modifier|*
name|Class2Record
decl_stmt|;
comment|/* array of Class2Record tables */
DECL|member|ValueRecords
name|HB_Short
modifier|*
name|ValueRecords
decl_stmt|;
block|}
DECL|member|c2r
name|c2r
union|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_Class1Record
typedef|typedef
name|struct
name|HB_Class1Record_
name|HB_Class1Record
typedef|;
end_typedef
begin_struct
DECL|struct|HB_PairPosFormat2_
struct|struct
name|HB_PairPosFormat2_
block|{
DECL|member|ClassDef1
name|HB_ClassDefinition
name|ClassDef1
decl_stmt|;
comment|/* class def. for first glyph     */
DECL|member|ClassDef2
name|HB_ClassDefinition
name|ClassDef2
decl_stmt|;
comment|/* class def. for second glyph    */
DECL|member|Class1Count
name|HB_UShort
name|Class1Count
decl_stmt|;
comment|/* number of classes in ClassDef1 					 table                          */
DECL|member|Class2Count
name|HB_UShort
name|Class2Count
decl_stmt|;
comment|/* number of classes in ClassDef2 					 table                          */
DECL|member|Class1Record
name|HB_Class1Record
modifier|*
name|Class1Record
decl_stmt|;
comment|/* array of Class1Record tables   */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PairPosFormat2
typedef|typedef
name|struct
name|HB_PairPosFormat2_
name|HB_PairPosFormat2
typedef|;
end_typedef
begin_struct
DECL|struct|HB_PairPos_
struct|struct
name|HB_PairPos_
block|{
DECL|member|PosFormat
name|HB_Byte
name|PosFormat
decl_stmt|;
comment|/* 1 or 2         */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table */
DECL|member|ValueFormat1
name|HB_UShort
name|ValueFormat1
decl_stmt|;
comment|/* format of ValueRecord table 					 for first glyph             */
DECL|member|ValueFormat2
name|HB_UShort
name|ValueFormat2
decl_stmt|;
comment|/* format of ValueRecord table 					 for second glyph            */
union|union
block|{
DECL|member|ppf1
name|HB_PairPosFormat1
name|ppf1
decl_stmt|;
DECL|member|ppf2
name|HB_PairPosFormat2
name|ppf2
decl_stmt|;
block|}
DECL|member|ppf
name|ppf
union|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PairPos
typedef|typedef
name|struct
name|HB_PairPos_
name|HB_PairPos
typedef|;
end_typedef
begin_comment
comment|/* LookupType 3 */
end_comment
begin_struct
DECL|struct|HB_EntryExitRecord_
struct|struct
name|HB_EntryExitRecord_
block|{
DECL|member|EntryAnchor
name|HB_Anchor
name|EntryAnchor
decl_stmt|;
comment|/* entry Anchor table */
DECL|member|ExitAnchor
name|HB_Anchor
name|ExitAnchor
decl_stmt|;
comment|/* exit Anchor table  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_EntryExitRecord
typedef|typedef
name|struct
name|HB_EntryExitRecord_
name|HB_EntryExitRecord
typedef|;
end_typedef
begin_struct
DECL|struct|HB_CursivePos_
struct|struct
name|HB_CursivePos_
block|{
DECL|member|PosFormat
name|HB_UShort
name|PosFormat
decl_stmt|;
comment|/* always 1                         */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table                   */
DECL|member|EntryExitCount
name|HB_UShort
name|EntryExitCount
decl_stmt|;
comment|/* number of EntryExitRecord tables */
DECL|member|EntryExitRecord
name|HB_EntryExitRecord
modifier|*
name|EntryExitRecord
decl_stmt|;
comment|/* array of EntryExitRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_CursivePos
typedef|typedef
name|struct
name|HB_CursivePos_
name|HB_CursivePos
typedef|;
end_typedef
begin_comment
comment|/* LookupType 4 */
end_comment
begin_struct
DECL|struct|HB_BaseRecord_
struct|struct
name|HB_BaseRecord_
block|{
DECL|member|BaseAnchor
name|HB_Anchor
modifier|*
name|BaseAnchor
decl_stmt|;
comment|/* array of base glyph anchor 					 tables                     */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_BaseRecord
typedef|typedef
name|struct
name|HB_BaseRecord_
name|HB_BaseRecord
typedef|;
end_typedef
begin_struct
DECL|struct|HB_BaseArray_
struct|struct
name|HB_BaseArray_
block|{
DECL|member|BaseCount
name|HB_UShort
name|BaseCount
decl_stmt|;
comment|/* number of BaseRecord tables */
DECL|member|BaseRecord
name|HB_BaseRecord
modifier|*
name|BaseRecord
decl_stmt|;
comment|/* array of BaseRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_BaseArray
typedef|typedef
name|struct
name|HB_BaseArray_
name|HB_BaseArray
typedef|;
end_typedef
begin_struct
DECL|struct|HB_MarkBasePos_
struct|struct
name|HB_MarkBasePos_
block|{
DECL|member|PosFormat
name|HB_UShort
name|PosFormat
decl_stmt|;
comment|/* always 1                  */
DECL|member|MarkCoverage
name|HB_Coverage
name|MarkCoverage
decl_stmt|;
comment|/* mark glyph coverage table */
DECL|member|BaseCoverage
name|HB_Coverage
name|BaseCoverage
decl_stmt|;
comment|/* base glyph coverage table */
DECL|member|ClassCount
name|HB_UShort
name|ClassCount
decl_stmt|;
comment|/* number of mark classes    */
DECL|member|MarkArray
name|HB_MarkArray
name|MarkArray
decl_stmt|;
comment|/* mark array table          */
DECL|member|BaseArray
name|HB_BaseArray
name|BaseArray
decl_stmt|;
comment|/* base array table          */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_MarkBasePos
typedef|typedef
name|struct
name|HB_MarkBasePos_
name|HB_MarkBasePos
typedef|;
end_typedef
begin_comment
comment|/* LookupType 5 */
end_comment
begin_struct
DECL|struct|HB_ComponentRecord_
struct|struct
name|HB_ComponentRecord_
block|{
DECL|member|LigatureAnchor
name|HB_Anchor
modifier|*
name|LigatureAnchor
decl_stmt|;
comment|/* array of ligature glyph anchor 					 tables                         */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ComponentRecord
typedef|typedef
name|struct
name|HB_ComponentRecord_
name|HB_ComponentRecord
typedef|;
end_typedef
begin_struct
DECL|struct|HB_LigatureAttach_
struct|struct
name|HB_LigatureAttach_
block|{
DECL|member|ComponentCount
name|HB_UShort
name|ComponentCount
decl_stmt|;
comment|/* number of ComponentRecord tables */
DECL|member|ComponentRecord
name|HB_ComponentRecord
modifier|*
name|ComponentRecord
decl_stmt|;
comment|/* array of ComponentRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_LigatureAttach
typedef|typedef
name|struct
name|HB_LigatureAttach_
name|HB_LigatureAttach
typedef|;
end_typedef
begin_struct
DECL|struct|HB_LigatureArray_
struct|struct
name|HB_LigatureArray_
block|{
DECL|member|LigatureCount
name|HB_UShort
name|LigatureCount
decl_stmt|;
comment|/* number of LigatureAttach tables */
DECL|member|LigatureAttach
name|HB_LigatureAttach
modifier|*
name|LigatureAttach
decl_stmt|;
comment|/* array of LigatureAttach tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_LigatureArray
typedef|typedef
name|struct
name|HB_LigatureArray_
name|HB_LigatureArray
typedef|;
end_typedef
begin_struct
DECL|struct|HB_MarkLigPos_
struct|struct
name|HB_MarkLigPos_
block|{
DECL|member|PosFormat
name|HB_UShort
name|PosFormat
decl_stmt|;
comment|/* always 1                      */
DECL|member|MarkCoverage
name|HB_Coverage
name|MarkCoverage
decl_stmt|;
comment|/* mark glyph coverage table     */
DECL|member|LigatureCoverage
name|HB_Coverage
name|LigatureCoverage
decl_stmt|;
comment|/* ligature glyph coverage table */
DECL|member|ClassCount
name|HB_UShort
name|ClassCount
decl_stmt|;
comment|/* number of mark classes        */
DECL|member|MarkArray
name|HB_MarkArray
name|MarkArray
decl_stmt|;
comment|/* mark array table              */
DECL|member|LigatureArray
name|HB_LigatureArray
name|LigatureArray
decl_stmt|;
comment|/* ligature array table          */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_MarkLigPos
typedef|typedef
name|struct
name|HB_MarkLigPos_
name|HB_MarkLigPos
typedef|;
end_typedef
begin_comment
comment|/* LookupType 6 */
end_comment
begin_struct
DECL|struct|HB_Mark2Record_
struct|struct
name|HB_Mark2Record_
block|{
DECL|member|Mark2Anchor
name|HB_Anchor
modifier|*
name|Mark2Anchor
decl_stmt|;
comment|/* array of mark glyph anchor 					 tables                     */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_Mark2Record
typedef|typedef
name|struct
name|HB_Mark2Record_
name|HB_Mark2Record
typedef|;
end_typedef
begin_struct
DECL|struct|HB_Mark2Array_
struct|struct
name|HB_Mark2Array_
block|{
DECL|member|Mark2Count
name|HB_UShort
name|Mark2Count
decl_stmt|;
comment|/* number of Mark2Record tables */
DECL|member|Mark2Record
name|HB_Mark2Record
modifier|*
name|Mark2Record
decl_stmt|;
comment|/* array of Mark2Record tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_Mark2Array
typedef|typedef
name|struct
name|HB_Mark2Array_
name|HB_Mark2Array
typedef|;
end_typedef
begin_struct
DECL|struct|HB_MarkMarkPos_
struct|struct
name|HB_MarkMarkPos_
block|{
DECL|member|PosFormat
name|HB_UShort
name|PosFormat
decl_stmt|;
comment|/* always 1                         */
DECL|member|Mark1Coverage
name|HB_Coverage
name|Mark1Coverage
decl_stmt|;
comment|/* first mark glyph coverage table  */
DECL|member|Mark2Coverage
name|HB_Coverage
name|Mark2Coverage
decl_stmt|;
comment|/* second mark glyph coverave table */
DECL|member|ClassCount
name|HB_UShort
name|ClassCount
decl_stmt|;
comment|/* number of combining mark classes */
DECL|member|Mark1Array
name|HB_MarkArray
name|Mark1Array
decl_stmt|;
comment|/* MarkArray table for first mark   */
DECL|member|Mark2Array
name|HB_Mark2Array
name|Mark2Array
decl_stmt|;
comment|/* MarkArray table for second mark  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_MarkMarkPos
typedef|typedef
name|struct
name|HB_MarkMarkPos_
name|HB_MarkMarkPos
typedef|;
end_typedef
begin_comment
comment|/* needed by both lookup type 7 and 8 */
end_comment
begin_struct
DECL|struct|HB_PosLookupRecord_
struct|struct
name|HB_PosLookupRecord_
block|{
DECL|member|SequenceIndex
name|HB_UShort
name|SequenceIndex
decl_stmt|;
comment|/* index into current 					 glyph sequence               */
DECL|member|LookupListIndex
name|HB_UShort
name|LookupListIndex
decl_stmt|;
comment|/* Lookup to apply to that pos. */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PosLookupRecord
typedef|typedef
name|struct
name|HB_PosLookupRecord_
name|HB_PosLookupRecord
typedef|;
end_typedef
begin_comment
comment|/* LookupType 7 */
end_comment
begin_struct
DECL|struct|HB_PosRule_
struct|struct
name|HB_PosRule_
block|{
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* total number of input glyphs     */
DECL|member|PosCount
name|HB_UShort
name|PosCount
decl_stmt|;
comment|/* number of PosLookupRecord tables */
DECL|member|Input
name|HB_UShort
modifier|*
name|Input
decl_stmt|;
comment|/* array of input glyph IDs         */
DECL|member|PosLookupRecord
name|HB_PosLookupRecord
modifier|*
name|PosLookupRecord
decl_stmt|;
comment|/* array of PosLookupRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PosRule
typedef|typedef
name|struct
name|HB_PosRule_
name|HB_PosRule
typedef|;
end_typedef
begin_struct
DECL|struct|HB_PosRuleSet_
struct|struct
name|HB_PosRuleSet_
block|{
DECL|member|PosRuleCount
name|HB_UShort
name|PosRuleCount
decl_stmt|;
comment|/* number of PosRule tables */
DECL|member|PosRule
name|HB_PosRule
modifier|*
name|PosRule
decl_stmt|;
comment|/* array of PosRule tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PosRuleSet
typedef|typedef
name|struct
name|HB_PosRuleSet_
name|HB_PosRuleSet
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ContextPosFormat1_
struct|struct
name|HB_ContextPosFormat1_
block|{
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table              */
DECL|member|PosRuleSetCount
name|HB_UShort
name|PosRuleSetCount
decl_stmt|;
comment|/* number of PosRuleSet tables */
DECL|member|PosRuleSet
name|HB_PosRuleSet
modifier|*
name|PosRuleSet
decl_stmt|;
comment|/* array of PosRuleSet tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ContextPosFormat1
typedef|typedef
name|struct
name|HB_ContextPosFormat1_
name|HB_ContextPosFormat1
typedef|;
end_typedef
begin_struct
DECL|struct|HB_PosClassRule_
struct|struct
name|HB_PosClassRule_
block|{
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* total number of context classes  */
DECL|member|PosCount
name|HB_UShort
name|PosCount
decl_stmt|;
comment|/* number of PosLookupRecord tables */
DECL|member|Class
name|HB_UShort
modifier|*
name|Class
decl_stmt|;
comment|/* array of classes                 */
DECL|member|PosLookupRecord
name|HB_PosLookupRecord
modifier|*
name|PosLookupRecord
decl_stmt|;
comment|/* array of PosLookupRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PosClassRule
typedef|typedef
name|struct
name|HB_PosClassRule_
name|HB_PosClassRule
typedef|;
end_typedef
begin_struct
DECL|struct|HB_PosClassSet_
struct|struct
name|HB_PosClassSet_
block|{
DECL|member|PosClassRuleCount
name|HB_UShort
name|PosClassRuleCount
decl_stmt|;
comment|/* number of PosClassRule tables */
DECL|member|PosClassRule
name|HB_PosClassRule
modifier|*
name|PosClassRule
decl_stmt|;
comment|/* array of PosClassRule tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_PosClassSet
typedef|typedef
name|struct
name|HB_PosClassSet_
name|HB_PosClassSet
typedef|;
end_typedef
begin_comment
comment|/* The `MaxContextLength' field is not defined in the TTO specification    but simplifies the implementation of this format.  It holds the    maximal context length used in the context rules.                    */
end_comment
begin_struct
DECL|struct|HB_ContextPosFormat2_
struct|struct
name|HB_ContextPosFormat2_
block|{
DECL|member|MaxContextLength
name|HB_UShort
name|MaxContextLength
decl_stmt|;
comment|/* maximal context length       */
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table               */
DECL|member|ClassDef
name|HB_ClassDefinition
name|ClassDef
decl_stmt|;
comment|/* ClassDef table               */
DECL|member|PosClassSetCount
name|HB_UShort
name|PosClassSetCount
decl_stmt|;
comment|/* number of PosClassSet tables */
DECL|member|PosClassSet
name|HB_PosClassSet
modifier|*
name|PosClassSet
decl_stmt|;
comment|/* array of PosClassSet tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ContextPosFormat2
typedef|typedef
name|struct
name|HB_ContextPosFormat2_
name|HB_ContextPosFormat2
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ContextPosFormat3_
struct|struct
name|HB_ContextPosFormat3_
block|{
DECL|member|GlyphCount
name|HB_UShort
name|GlyphCount
decl_stmt|;
comment|/* number of input glyphs           */
DECL|member|PosCount
name|HB_UShort
name|PosCount
decl_stmt|;
comment|/* number of PosLookupRecord tables */
DECL|member|Coverage
name|HB_Coverage
modifier|*
name|Coverage
decl_stmt|;
comment|/* array of Coverage tables         */
DECL|member|PosLookupRecord
name|HB_PosLookupRecord
modifier|*
name|PosLookupRecord
decl_stmt|;
comment|/* array of PosLookupRecord tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ContextPosFormat3
typedef|typedef
name|struct
name|HB_ContextPosFormat3_
name|HB_ContextPosFormat3
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ContextPos_
struct|struct
name|HB_ContextPos_
block|{
DECL|member|PosFormat
name|HB_Byte
name|PosFormat
decl_stmt|;
comment|/* 1, 2, or 3     */
union|union
block|{
DECL|member|cpf1
name|HB_ContextPosFormat1
name|cpf1
decl_stmt|;
DECL|member|cpf2
name|HB_ContextPosFormat2
name|cpf2
decl_stmt|;
DECL|member|cpf3
name|HB_ContextPosFormat3
name|cpf3
decl_stmt|;
block|}
DECL|member|cpf
name|cpf
union|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ContextPos
typedef|typedef
name|struct
name|HB_ContextPos_
name|HB_ContextPos
typedef|;
end_typedef
begin_comment
comment|/* LookupType 8 */
end_comment
begin_struct
DECL|struct|HB_ChainPosRule_
struct|struct
name|HB_ChainPosRule_
block|{
DECL|member|Backtrack
name|HB_UShort
modifier|*
name|Backtrack
decl_stmt|;
comment|/* array of backtrack glyph IDs     */
DECL|member|Input
name|HB_UShort
modifier|*
name|Input
decl_stmt|;
comment|/* array of input glyph IDs         */
DECL|member|Lookahead
name|HB_UShort
modifier|*
name|Lookahead
decl_stmt|;
comment|/* array of lookahead glyph IDs     */
DECL|member|PosLookupRecord
name|HB_PosLookupRecord
modifier|*
name|PosLookupRecord
decl_stmt|;
comment|/* array of PosLookupRecords       */
DECL|member|BacktrackGlyphCount
name|HB_UShort
name|BacktrackGlyphCount
decl_stmt|;
comment|/* total number of backtrack glyphs */
DECL|member|InputGlyphCount
name|HB_UShort
name|InputGlyphCount
decl_stmt|;
comment|/* total number of input glyphs     */
DECL|member|LookaheadGlyphCount
name|HB_UShort
name|LookaheadGlyphCount
decl_stmt|;
comment|/* total number of lookahead glyphs */
DECL|member|PosCount
name|HB_UShort
name|PosCount
decl_stmt|;
comment|/* number of PosLookupRecords       */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainPosRule
typedef|typedef
name|struct
name|HB_ChainPosRule_
name|HB_ChainPosRule
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainPosRuleSet_
struct|struct
name|HB_ChainPosRuleSet_
block|{
DECL|member|ChainPosRuleCount
name|HB_UShort
name|ChainPosRuleCount
decl_stmt|;
comment|/* number of ChainPosRule tables */
DECL|member|ChainPosRule
name|HB_ChainPosRule
modifier|*
name|ChainPosRule
decl_stmt|;
comment|/* array of ChainPosRule tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainPosRuleSet
typedef|typedef
name|struct
name|HB_ChainPosRuleSet_
name|HB_ChainPosRuleSet
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainContextPosFormat1_
struct|struct
name|HB_ChainContextPosFormat1_
block|{
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table                   */
DECL|member|ChainPosRuleSetCount
name|HB_UShort
name|ChainPosRuleSetCount
decl_stmt|;
comment|/* number of ChainPosRuleSet tables */
DECL|member|ChainPosRuleSet
name|HB_ChainPosRuleSet
modifier|*
name|ChainPosRuleSet
decl_stmt|;
comment|/* array of ChainPosRuleSet tables  */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainContextPosFormat1
typedef|typedef
name|struct
name|HB_ChainContextPosFormat1_
name|HB_ChainContextPosFormat1
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainPosClassRule_
struct|struct
name|HB_ChainPosClassRule_
block|{
DECL|member|Backtrack
name|HB_UShort
modifier|*
name|Backtrack
decl_stmt|;
comment|/* array of backtrack classes      */
DECL|member|Input
name|HB_UShort
modifier|*
name|Input
decl_stmt|;
comment|/* array of context classes        */
DECL|member|Lookahead
name|HB_UShort
modifier|*
name|Lookahead
decl_stmt|;
comment|/* array of lookahead classes      */
DECL|member|PosLookupRecord
name|HB_PosLookupRecord
modifier|*
name|PosLookupRecord
decl_stmt|;
comment|/* array of substitution lookups   */
DECL|member|BacktrackGlyphCount
name|HB_UShort
name|BacktrackGlyphCount
decl_stmt|;
comment|/* total number of backtrack 					 classes                         */
DECL|member|InputGlyphCount
name|HB_UShort
name|InputGlyphCount
decl_stmt|;
comment|/* total number of context classes */
DECL|member|LookaheadGlyphCount
name|HB_UShort
name|LookaheadGlyphCount
decl_stmt|;
comment|/* total number of lookahead 					 classes                         */
DECL|member|PosCount
name|HB_UShort
name|PosCount
decl_stmt|;
comment|/* number of PosLookupRecords      */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainPosClassRule
typedef|typedef
name|struct
name|HB_ChainPosClassRule_
name|HB_ChainPosClassRule
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainPosClassSet_
struct|struct
name|HB_ChainPosClassSet_
block|{
DECL|member|ChainPosClassRuleCount
name|HB_UShort
name|ChainPosClassRuleCount
decl_stmt|;
comment|/* number of ChainPosClassRule 					 tables                      */
DECL|member|ChainPosClassRule
name|HB_ChainPosClassRule
modifier|*
name|ChainPosClassRule
decl_stmt|;
comment|/* array of ChainPosClassRule 					 tables                      */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainPosClassSet
typedef|typedef
name|struct
name|HB_ChainPosClassSet_
name|HB_ChainPosClassSet
typedef|;
end_typedef
begin_comment
comment|/* The `MaxXXXLength' fields are not defined in the TTO specification    but simplifies the implementation of this format.  It holds the    maximal context length used in the specific context rules.         */
end_comment
begin_struct
DECL|struct|HB_ChainContextPosFormat2_
struct|struct
name|HB_ChainContextPosFormat2_
block|{
DECL|member|Coverage
name|HB_Coverage
name|Coverage
decl_stmt|;
comment|/* Coverage table             */
DECL|member|MaxBacktrackLength
name|HB_UShort
name|MaxBacktrackLength
decl_stmt|;
comment|/* maximal backtrack length   */
DECL|member|BacktrackClassDef
name|HB_ClassDefinition
name|BacktrackClassDef
decl_stmt|;
comment|/* BacktrackClassDef table    */
DECL|member|MaxInputLength
name|HB_UShort
name|MaxInputLength
decl_stmt|;
comment|/* maximal input length       */
DECL|member|InputClassDef
name|HB_ClassDefinition
name|InputClassDef
decl_stmt|;
comment|/* InputClassDef table        */
DECL|member|MaxLookaheadLength
name|HB_UShort
name|MaxLookaheadLength
decl_stmt|;
comment|/* maximal lookahead length   */
DECL|member|LookaheadClassDef
name|HB_ClassDefinition
name|LookaheadClassDef
decl_stmt|;
comment|/* LookaheadClassDef table    */
DECL|member|ChainPosClassSetCount
name|HB_UShort
name|ChainPosClassSetCount
decl_stmt|;
comment|/* number of ChainPosClassSet 					 tables                     */
DECL|member|ChainPosClassSet
name|HB_ChainPosClassSet
modifier|*
name|ChainPosClassSet
decl_stmt|;
comment|/* array of ChainPosClassSet 					 tables                     */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainContextPosFormat2
typedef|typedef
name|struct
name|HB_ChainContextPosFormat2_
name|HB_ChainContextPosFormat2
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainContextPosFormat3_
struct|struct
name|HB_ChainContextPosFormat3_
block|{
DECL|member|BacktrackGlyphCount
name|HB_UShort
name|BacktrackGlyphCount
decl_stmt|;
comment|/* number of backtrack glyphs    */
DECL|member|BacktrackCoverage
name|HB_Coverage
modifier|*
name|BacktrackCoverage
decl_stmt|;
comment|/* array of backtrack Coverage 					 tables                        */
DECL|member|InputGlyphCount
name|HB_UShort
name|InputGlyphCount
decl_stmt|;
comment|/* number of input glyphs        */
DECL|member|InputCoverage
name|HB_Coverage
modifier|*
name|InputCoverage
decl_stmt|;
comment|/* array of input coverage 					 tables                        */
DECL|member|LookaheadGlyphCount
name|HB_UShort
name|LookaheadGlyphCount
decl_stmt|;
comment|/* number of lookahead glyphs    */
DECL|member|LookaheadCoverage
name|HB_Coverage
modifier|*
name|LookaheadCoverage
decl_stmt|;
comment|/* array of lookahead coverage 					 tables                        */
DECL|member|PosCount
name|HB_UShort
name|PosCount
decl_stmt|;
comment|/* number of PosLookupRecords    */
DECL|member|PosLookupRecord
name|HB_PosLookupRecord
modifier|*
name|PosLookupRecord
decl_stmt|;
comment|/* array of substitution lookups */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainContextPosFormat3
typedef|typedef
name|struct
name|HB_ChainContextPosFormat3_
name|HB_ChainContextPosFormat3
typedef|;
end_typedef
begin_struct
DECL|struct|HB_ChainContextPos_
struct|struct
name|HB_ChainContextPos_
block|{
DECL|member|PosFormat
name|HB_Byte
name|PosFormat
decl_stmt|;
comment|/* 1, 2, or 3 */
union|union
block|{
DECL|member|ccpf1
name|HB_ChainContextPosFormat1
name|ccpf1
decl_stmt|;
DECL|member|ccpf2
name|HB_ChainContextPosFormat2
name|ccpf2
decl_stmt|;
DECL|member|ccpf3
name|HB_ChainContextPosFormat3
name|ccpf3
decl_stmt|;
block|}
DECL|member|ccpf
name|ccpf
union|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HB_ChainContextPos
typedef|typedef
name|struct
name|HB_ChainContextPos_
name|HB_ChainContextPos
typedef|;
end_typedef
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* LookupType 10 */
end_comment
begin_comment
unit|struct HB_ExtensionPos_ {   HB_UShort      PosFormat;
comment|/* always 1 */
end_comment
begin_comment
unit|HB_UShort      LookuptType;
comment|/* lookup-type of referenced subtable */
end_comment
begin_comment
unit|HB_GPOS_SubTable *subtable;
comment|/* referenced subtable */
end_comment
begin_endif
unit|};  typedef struct HB_ExtensionPos_  HB_ExtensionPos;
endif|#
directive|endif
end_endif
begin_union
DECL|union|HB_GPOS_SubTable_
union|union
name|HB_GPOS_SubTable_
block|{
DECL|member|single
name|HB_SinglePos
name|single
decl_stmt|;
DECL|member|pair
name|HB_PairPos
name|pair
decl_stmt|;
DECL|member|cursive
name|HB_CursivePos
name|cursive
decl_stmt|;
DECL|member|markbase
name|HB_MarkBasePos
name|markbase
decl_stmt|;
DECL|member|marklig
name|HB_MarkLigPos
name|marklig
decl_stmt|;
DECL|member|markmark
name|HB_MarkMarkPos
name|markmark
decl_stmt|;
DECL|member|context
name|HB_ContextPos
name|context
decl_stmt|;
DECL|member|chain
name|HB_ChainContextPos
name|chain
decl_stmt|;
block|}
union|;
end_union
begin_typedef
DECL|typedef|HB_GPOS_SubTable
typedef|typedef
name|union
name|HB_GPOS_SubTable_
name|HB_GPOS_SubTable
typedef|;
end_typedef
begin_function_decl
name|HB_INTERNAL
name|HB_Error
name|_HB_GPOS_Load_SubTable
parameter_list|(
name|HB_GPOS_SubTable
modifier|*
name|st
parameter_list|,
name|HB_Stream
name|stream
parameter_list|,
name|HB_UShort
name|lookup_type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|HB_INTERNAL
name|void
name|_HB_GPOS_Free_SubTable
parameter_list|(
name|HB_GPOS_SubTable
modifier|*
name|st
parameter_list|,
name|HB_UShort
name|lookup_type
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|HB_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* HARFBUZZ_GPOS_PRIVATE_H */
end_comment
end_unit
