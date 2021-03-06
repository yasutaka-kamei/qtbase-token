begin_unit
begin_comment
comment|/*  * transupp.h  *  * Copyright (C) 1997-2009, Thomas G. Lane, Guido Vollbeding.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file contains declarations for image transformation routines and  * other utility code used by the jpegtran sample application.  These are  * NOT part of the core JPEG library.  But we keep these routines separate  * from jpegtran.c to ease the task of maintaining jpegtran-like programs  * that have other user interfaces.  *  * NOTE: all the routines declared here have very specific requirements  * about when they are to be executed during the reading and writing of the  * source and destination files.  See the comments in transupp.c, or see  * jpegtran.c for an example of correct usage.  */
end_comment
begin_comment
comment|/* If you happen not to want the image transform support, disable it here */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TRANSFORMS_SUPPORTED
end_ifndef
begin_define
DECL|macro|TRANSFORMS_SUPPORTED
define|#
directive|define
name|TRANSFORMS_SUPPORTED
value|1
end_define
begin_comment
DECL|macro|TRANSFORMS_SUPPORTED
comment|/* 0 disables transform code */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * Although rotating and flipping data expressed as DCT coefficients is not  * hard, there is an asymmetry in the JPEG format specification for images  * whose dimensions aren't multiples of the iMCU size.  The right and bottom  * image edges are padded out to the next iMCU boundary with junk data; but  * no padding is possible at the top and left edges.  If we were to flip  * the whole image including the pad data, then pad garbage would become  * visible at the top and/or left, and real pixels would disappear into the  * pad margins --- perhaps permanently, since encoders& decoders may not  * bother to preserve DCT blocks that appear to be completely outside the  * nominal image area.  So, we have to exclude any partial iMCUs from the  * basic transformation.  *  * Transpose is the only transformation that can handle partial iMCUs at the  * right and bottom edges completely cleanly.  flip_h can flip partial iMCUs  * at the bottom, but leaves any partial iMCUs at the right edge untouched.  * Similarly flip_v leaves any partial iMCUs at the bottom edge untouched.  * The other transforms are defined as combinations of these basic transforms  * and process edge blocks in a way that preserves the equivalence.  *  * The "trim" option causes untransformable partial iMCUs to be dropped;  * this is not strictly lossless, but it usually gives the best-looking  * result for odd-size images.  Note that when this option is active,  * the expected mathematical equivalences between the transforms may not hold.  * (For example, -rot 270 -trim trims only the bottom edge, but -rot 90 -trim  * followed by -rot 180 -trim trims both edges.)  *  * We also offer a lossless-crop option, which discards data outside a given  * image region but losslessly preserves what is inside.  Like the rotate and  * flip transforms, lossless crop is restricted by the JPEG format: the upper  * left corner of the selected region must fall on an iMCU boundary.  If this  * does not hold for the given crop parameters, we silently move the upper left  * corner up and/or left to make it so, simultaneously increasing the region  * dimensions to keep the lower right crop corner unchanged.  (Thus, the  * output image covers at least the requested region, but may cover more.)  *  * We also provide a lossless-resize option, which is kind of a lossless-crop  * operation in the DCT coefficient block domain - it discards higher-order  * coefficients and losslessly preserves lower-order coefficients of a  * sub-block.  *  * Rotate/flip transform, resize, and crop can be requested together in a  * single invocation.  The crop is applied last --- that is, the crop region  * is specified in terms of the destination image after transform/resize.  *  * We also offer a "force to grayscale" option, which simply discards the  * chrominance channels of a YCbCr image.  This is lossless in the sense that  * the luminance channel is preserved exactly.  It's not the same kind of  * thing as the rotate/flip transformations, but it's convenient to handle it  * as part of this package, mainly because the transformation routines have to  * be aware of the option to know how many components to work on.  */
end_comment
begin_comment
comment|/* Short forms of external names for systems with brain-damaged linkers. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SHORT_EXTERNAL_NAMES
end_ifdef
begin_define
DECL|macro|jtransform_parse_crop_spec
define|#
directive|define
name|jtransform_parse_crop_spec
value|jTrParCrop
end_define
begin_define
DECL|macro|jtransform_request_workspace
define|#
directive|define
name|jtransform_request_workspace
value|jTrRequest
end_define
begin_define
DECL|macro|jtransform_adjust_parameters
define|#
directive|define
name|jtransform_adjust_parameters
value|jTrAdjust
end_define
begin_define
DECL|macro|jtransform_execute_transform
define|#
directive|define
name|jtransform_execute_transform
value|jTrExec
end_define
begin_define
DECL|macro|jtransform_perfect_transform
define|#
directive|define
name|jtransform_perfect_transform
value|jTrPerfect
end_define
begin_define
DECL|macro|jcopy_markers_setup
define|#
directive|define
name|jcopy_markers_setup
value|jCMrkSetup
end_define
begin_define
DECL|macro|jcopy_markers_execute
define|#
directive|define
name|jcopy_markers_execute
value|jCMrkExec
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* NEED_SHORT_EXTERNAL_NAMES */
end_comment
begin_comment
comment|/*  * Codes for supported types of image transformations.  */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|JXFORM_NONE
name|JXFORM_NONE
block|,
comment|/* no transformation */
DECL|enumerator|JXFORM_FLIP_H
name|JXFORM_FLIP_H
block|,
comment|/* horizontal flip */
DECL|enumerator|JXFORM_FLIP_V
name|JXFORM_FLIP_V
block|,
comment|/* vertical flip */
DECL|enumerator|JXFORM_TRANSPOSE
name|JXFORM_TRANSPOSE
block|,
comment|/* transpose across UL-to-LR axis */
DECL|enumerator|JXFORM_TRANSVERSE
name|JXFORM_TRANSVERSE
block|,
comment|/* transpose across UR-to-LL axis */
DECL|enumerator|JXFORM_ROT_90
name|JXFORM_ROT_90
block|,
comment|/* 90-degree clockwise rotation */
DECL|enumerator|JXFORM_ROT_180
name|JXFORM_ROT_180
block|,
comment|/* 180-degree rotation */
DECL|enumerator|JXFORM_ROT_270
name|JXFORM_ROT_270
comment|/* 270-degree clockwise (or 90 ccw) */
block|}
DECL|typedef|JXFORM_CODE
name|JXFORM_CODE
typedef|;
end_typedef
begin_comment
comment|/*  * Codes for crop parameters, which can individually be unspecified,  * positive, or negative.  (Negative width or height makes no sense, though.)  */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|JCROP_UNSET
name|JCROP_UNSET
block|,
DECL|enumerator|JCROP_POS
name|JCROP_POS
block|,
DECL|enumerator|JCROP_NEG
name|JCROP_NEG
block|}
DECL|typedef|JCROP_CODE
name|JCROP_CODE
typedef|;
end_typedef
begin_comment
comment|/*  * Transform parameters struct.  * NB: application must not change any elements of this struct after  * calling jtransform_request_workspace.  */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Options: set by caller */
DECL|member|transform
name|JXFORM_CODE
name|transform
decl_stmt|;
comment|/* image transform operator */
DECL|member|perfect
name|boolean
name|perfect
decl_stmt|;
comment|/* if TRUE, fail if partial MCUs are requested */
DECL|member|trim
name|boolean
name|trim
decl_stmt|;
comment|/* if TRUE, trim partial MCUs as needed */
DECL|member|force_grayscale
name|boolean
name|force_grayscale
decl_stmt|;
comment|/* if TRUE, convert color image to grayscale */
DECL|member|crop
name|boolean
name|crop
decl_stmt|;
comment|/* if TRUE, crop source image */
comment|/* Crop parameters: application need not set these unless crop is TRUE.    * These can be filled in by jtransform_parse_crop_spec().    */
DECL|member|crop_width
name|JDIMENSION
name|crop_width
decl_stmt|;
comment|/* Width of selected region */
DECL|member|crop_width_set
name|JCROP_CODE
name|crop_width_set
decl_stmt|;
DECL|member|crop_height
name|JDIMENSION
name|crop_height
decl_stmt|;
comment|/* Height of selected region */
DECL|member|crop_height_set
name|JCROP_CODE
name|crop_height_set
decl_stmt|;
DECL|member|crop_xoffset
name|JDIMENSION
name|crop_xoffset
decl_stmt|;
comment|/* X offset of selected region */
DECL|member|crop_xoffset_set
name|JCROP_CODE
name|crop_xoffset_set
decl_stmt|;
comment|/* (negative measures from right edge) */
DECL|member|crop_yoffset
name|JDIMENSION
name|crop_yoffset
decl_stmt|;
comment|/* Y offset of selected region */
DECL|member|crop_yoffset_set
name|JCROP_CODE
name|crop_yoffset_set
decl_stmt|;
comment|/* (negative measures from bottom edge) */
comment|/* Internal workspace: caller should not touch these */
DECL|member|num_components
name|int
name|num_components
decl_stmt|;
comment|/* # of components in workspace */
DECL|member|workspace_coef_arrays
name|jvirt_barray_ptr
modifier|*
name|workspace_coef_arrays
decl_stmt|;
comment|/* workspace for transformations */
DECL|member|output_width
name|JDIMENSION
name|output_width
decl_stmt|;
comment|/* cropped destination dimensions */
DECL|member|output_height
name|JDIMENSION
name|output_height
decl_stmt|;
DECL|member|x_crop_offset
name|JDIMENSION
name|x_crop_offset
decl_stmt|;
comment|/* destination crop offsets measured in iMCUs */
DECL|member|y_crop_offset
name|JDIMENSION
name|y_crop_offset
decl_stmt|;
DECL|member|iMCU_sample_width
name|int
name|iMCU_sample_width
decl_stmt|;
comment|/* destination iMCU size */
DECL|member|iMCU_sample_height
name|int
name|iMCU_sample_height
decl_stmt|;
block|}
DECL|typedef|jpeg_transform_info
name|jpeg_transform_info
typedef|;
end_typedef
begin_if
if|#
directive|if
name|TRANSFORMS_SUPPORTED
end_if
begin_comment
comment|/* Parse a crop specification (written in X11 geometry style) */
end_comment
begin_macro
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
end_macro
begin_decl_stmt
name|jtransform_parse_crop_spec
name|JPP
argument_list|(
operator|(
name|jpeg_transform_info
operator|*
name|info
operator|,
specifier|const
name|char
operator|*
name|spec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Request any required workspace */
end_comment
begin_macro
DECL|variable|jtransform_request_workspace
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|jtransform_request_workspace
name|jtransform_request_workspace
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|srcinfo
operator|,
name|jpeg_transform_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Adjust output image parameters */
end_comment
begin_macro
name|EXTERN
argument_list|(
argument|jvirt_barray_ptr *
argument_list|)
end_macro
begin_decl_stmt
name|jtransform_adjust_parameters
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|srcinfo
operator|,
name|j_compress_ptr
name|dstinfo
operator|,
name|jvirt_barray_ptr
operator|*
name|src_coef_arrays
operator|,
name|jpeg_transform_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Execute the actual transformation, if any */
end_comment
begin_macro
name|EXTERN
argument_list|(
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|jtransform_execute_transform
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|srcinfo
operator|,
name|j_compress_ptr
name|dstinfo
operator|,
name|jvirt_barray_ptr
operator|*
name|src_coef_arrays
operator|,
name|jpeg_transform_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Determine whether lossless transformation is perfectly  * possible for a specified image and transformation.  */
end_comment
begin_macro
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
end_macro
begin_decl_stmt
name|jtransform_perfect_transform
name|JPP
argument_list|(
operator|(
name|JDIMENSION
name|image_width
operator|,
name|JDIMENSION
name|image_height
operator|,
name|int
name|MCU_width
operator|,
name|int
name|MCU_height
operator|,
name|JXFORM_CODE
name|transform
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* jtransform_execute_transform used to be called  * jtransform_execute_transformation, but some compilers complain about  * routine names that long.  This macro is here to avoid breaking any  * old source code that uses the original name...  */
end_comment
begin_define
DECL|macro|jtransform_execute_transformation
define|#
directive|define
name|jtransform_execute_transformation
value|jtransform_execute_transform
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TRANSFORMS_SUPPORTED */
end_comment
begin_comment
comment|/*  * Support for copying optional markers from source to destination file.  */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|JCOPYOPT_NONE
name|JCOPYOPT_NONE
block|,
comment|/* copy no optional markers */
DECL|enumerator|JCOPYOPT_COMMENTS
name|JCOPYOPT_COMMENTS
block|,
comment|/* copy only comment (COM) markers */
DECL|enumerator|JCOPYOPT_ALL
name|JCOPYOPT_ALL
comment|/* copy all optional markers */
block|}
DECL|typedef|JCOPY_OPTION
name|JCOPY_OPTION
typedef|;
end_typedef
begin_define
DECL|macro|JCOPYOPT_DEFAULT
define|#
directive|define
name|JCOPYOPT_DEFAULT
value|JCOPYOPT_COMMENTS
end_define
begin_comment
DECL|macro|JCOPYOPT_DEFAULT
comment|/* recommended default */
end_comment
begin_comment
comment|/* Setup decompression object to save desired markers in memory */
end_comment
begin_macro
name|EXTERN
argument_list|(
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|jcopy_markers_setup
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|srcinfo
operator|,
name|JCOPY_OPTION
name|option
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Copy markers saved in the given source object to the destination object */
end_comment
begin_macro
name|EXTERN
argument_list|(
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|jcopy_markers_execute
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|srcinfo
operator|,
name|j_compress_ptr
name|dstinfo
operator|,
name|JCOPY_OPTION
name|option
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
end_unit
