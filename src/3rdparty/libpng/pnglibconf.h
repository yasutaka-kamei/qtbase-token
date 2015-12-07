begin_unit
begin_comment
comment|/* pnglibconf.h - library build configuration */
end_comment
begin_comment
comment|/* libpng version 1.6.19, July 23, 2015 */
end_comment
begin_comment
comment|/* Copyright (c) 1998-2014 Glenn Randers-Pehrson */
end_comment
begin_comment
comment|/* This code is released under the libpng license. */
end_comment
begin_comment
comment|/* For conditions of distribution and use, see the disclaimer */
end_comment
begin_comment
comment|/* and license in png.h */
end_comment
begin_comment
comment|/* pnglibconf.h */
end_comment
begin_comment
comment|/* Machine generated file: DO NOT EDIT */
end_comment
begin_comment
comment|/* Derived from: scripts/pnglibconf.dfa */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PNGLCONF_H
end_ifndef
begin_define
DECL|macro|PNGLCONF_H
define|#
directive|define
name|PNGLCONF_H
end_define
begin_comment
comment|/* options */
end_comment
begin_define
DECL|macro|PNG_16BIT_SUPPORTED
define|#
directive|define
name|PNG_16BIT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_ALIGNED_MEMORY_SUPPORTED
define|#
directive|define
name|PNG_ALIGNED_MEMORY_SUPPORTED
end_define
begin_comment
comment|/*#undef PNG_ARM_NEON_API_SUPPORTED*/
end_comment
begin_comment
comment|/*#undef PNG_ARM_NEON_CHECK_SUPPORTED*/
end_comment
begin_define
DECL|macro|PNG_BENIGN_ERRORS_SUPPORTED
define|#
directive|define
name|PNG_BENIGN_ERRORS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_BENIGN_READ_ERRORS_SUPPORTED
define|#
directive|define
name|PNG_BENIGN_READ_ERRORS_SUPPORTED
end_define
begin_comment
comment|/*#undef PNG_BENIGN_WRITE_ERRORS_SUPPORTED*/
end_comment
begin_define
DECL|macro|PNG_BUILD_GRAYSCALE_PALETTE_SUPPORTED
define|#
directive|define
name|PNG_BUILD_GRAYSCALE_PALETTE_SUPPORTED
end_define
begin_define
DECL|macro|PNG_CHECK_FOR_INVALID_INDEX_SUPPORTED
define|#
directive|define
name|PNG_CHECK_FOR_INVALID_INDEX_SUPPORTED
end_define
begin_define
DECL|macro|PNG_COLORSPACE_SUPPORTED
define|#
directive|define
name|PNG_COLORSPACE_SUPPORTED
end_define
begin_define
DECL|macro|PNG_CONSOLE_IO_SUPPORTED
define|#
directive|define
name|PNG_CONSOLE_IO_SUPPORTED
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef
begin_define
DECL|macro|PNG_CONVERT_tIME_SUPPORTED
define|#
directive|define
name|PNG_CONVERT_tIME_SUPPORTED
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|PNG_EASY_ACCESS_SUPPORTED
define|#
directive|define
name|PNG_EASY_ACCESS_SUPPORTED
end_define
begin_comment
comment|/*#undef PNG_ERROR_NUMBERS_SUPPORTED*/
end_comment
begin_define
DECL|macro|PNG_ERROR_TEXT_SUPPORTED
define|#
directive|define
name|PNG_ERROR_TEXT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_FIXED_POINT_SUPPORTED
define|#
directive|define
name|PNG_FIXED_POINT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_FLOATING_ARITHMETIC_SUPPORTED
define|#
directive|define
name|PNG_FLOATING_ARITHMETIC_SUPPORTED
end_define
begin_define
DECL|macro|PNG_FLOATING_POINT_SUPPORTED
define|#
directive|define
name|PNG_FLOATING_POINT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_FORMAT_AFIRST_SUPPORTED
define|#
directive|define
name|PNG_FORMAT_AFIRST_SUPPORTED
end_define
begin_define
DECL|macro|PNG_FORMAT_BGR_SUPPORTED
define|#
directive|define
name|PNG_FORMAT_BGR_SUPPORTED
end_define
begin_define
DECL|macro|PNG_GAMMA_SUPPORTED
define|#
directive|define
name|PNG_GAMMA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_GET_PALETTE_MAX_SUPPORTED
define|#
directive|define
name|PNG_GET_PALETTE_MAX_SUPPORTED
end_define
begin_define
DECL|macro|PNG_HANDLE_AS_UNKNOWN_SUPPORTED
define|#
directive|define
name|PNG_HANDLE_AS_UNKNOWN_SUPPORTED
end_define
begin_define
DECL|macro|PNG_INCH_CONVERSIONS_SUPPORTED
define|#
directive|define
name|PNG_INCH_CONVERSIONS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_INFO_IMAGE_SUPPORTED
define|#
directive|define
name|PNG_INFO_IMAGE_SUPPORTED
end_define
begin_define
DECL|macro|PNG_IO_STATE_SUPPORTED
define|#
directive|define
name|PNG_IO_STATE_SUPPORTED
end_define
begin_define
DECL|macro|PNG_MNG_FEATURES_SUPPORTED
define|#
directive|define
name|PNG_MNG_FEATURES_SUPPORTED
end_define
begin_define
DECL|macro|PNG_POINTER_INDEXING_SUPPORTED
define|#
directive|define
name|PNG_POINTER_INDEXING_SUPPORTED
end_define
begin_define
DECL|macro|PNG_PROGRESSIVE_READ_SUPPORTED
define|#
directive|define
name|PNG_PROGRESSIVE_READ_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_16BIT_SUPPORTED
define|#
directive|define
name|PNG_READ_16BIT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_ALPHA_MODE_SUPPORTED
define|#
directive|define
name|PNG_READ_ALPHA_MODE_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_ANCILLARY_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_READ_ANCILLARY_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_BACKGROUND_SUPPORTED
define|#
directive|define
name|PNG_READ_BACKGROUND_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_BGR_SUPPORTED
define|#
directive|define
name|PNG_READ_BGR_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_CHECK_FOR_INVALID_INDEX_SUPPORTED
define|#
directive|define
name|PNG_READ_CHECK_FOR_INVALID_INDEX_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_COMPOSITE_NODIV_SUPPORTED
define|#
directive|define
name|PNG_READ_COMPOSITE_NODIV_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_COMPRESSED_TEXT_SUPPORTED
define|#
directive|define
name|PNG_READ_COMPRESSED_TEXT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_EXPAND_16_SUPPORTED
define|#
directive|define
name|PNG_READ_EXPAND_16_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_EXPAND_SUPPORTED
define|#
directive|define
name|PNG_READ_EXPAND_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_FILLER_SUPPORTED
define|#
directive|define
name|PNG_READ_FILLER_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_GAMMA_SUPPORTED
define|#
directive|define
name|PNG_READ_GAMMA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_GET_PALETTE_MAX_SUPPORTED
define|#
directive|define
name|PNG_READ_GET_PALETTE_MAX_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_GRAY_TO_RGB_SUPPORTED
define|#
directive|define
name|PNG_READ_GRAY_TO_RGB_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_INTERLACING_SUPPORTED
define|#
directive|define
name|PNG_READ_INTERLACING_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_INT_FUNCTIONS_SUPPORTED
define|#
directive|define
name|PNG_READ_INT_FUNCTIONS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_INVERT_ALPHA_SUPPORTED
define|#
directive|define
name|PNG_READ_INVERT_ALPHA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_INVERT_SUPPORTED
define|#
directive|define
name|PNG_READ_INVERT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_OPT_PLTE_SUPPORTED
define|#
directive|define
name|PNG_READ_OPT_PLTE_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_PACKSWAP_SUPPORTED
define|#
directive|define
name|PNG_READ_PACKSWAP_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_PACK_SUPPORTED
define|#
directive|define
name|PNG_READ_PACK_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_QUANTIZE_SUPPORTED
define|#
directive|define
name|PNG_READ_QUANTIZE_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_RGB_TO_GRAY_SUPPORTED
define|#
directive|define
name|PNG_READ_RGB_TO_GRAY_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_SCALE_16_TO_8_SUPPORTED
define|#
directive|define
name|PNG_READ_SCALE_16_TO_8_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_SHIFT_SUPPORTED
define|#
directive|define
name|PNG_READ_SHIFT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_STRIP_16_TO_8_SUPPORTED
define|#
directive|define
name|PNG_READ_STRIP_16_TO_8_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_STRIP_ALPHA_SUPPORTED
define|#
directive|define
name|PNG_READ_STRIP_ALPHA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_SUPPORTED
define|#
directive|define
name|PNG_READ_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_SWAP_ALPHA_SUPPORTED
define|#
directive|define
name|PNG_READ_SWAP_ALPHA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_SWAP_SUPPORTED
define|#
directive|define
name|PNG_READ_SWAP_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_TEXT_SUPPORTED
define|#
directive|define
name|PNG_READ_TEXT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_TRANSFORMS_SUPPORTED
define|#
directive|define
name|PNG_READ_TRANSFORMS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_USER_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_READ_USER_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_USER_TRANSFORM_SUPPORTED
define|#
directive|define
name|PNG_READ_USER_TRANSFORM_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_bKGD_SUPPORTED
define|#
directive|define
name|PNG_READ_bKGD_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_cHRM_SUPPORTED
define|#
directive|define
name|PNG_READ_cHRM_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_gAMA_SUPPORTED
define|#
directive|define
name|PNG_READ_gAMA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_hIST_SUPPORTED
define|#
directive|define
name|PNG_READ_hIST_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_iCCP_SUPPORTED
define|#
directive|define
name|PNG_READ_iCCP_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_iTXt_SUPPORTED
define|#
directive|define
name|PNG_READ_iTXt_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_oFFs_SUPPORTED
define|#
directive|define
name|PNG_READ_oFFs_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_pCAL_SUPPORTED
define|#
directive|define
name|PNG_READ_pCAL_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_pHYs_SUPPORTED
define|#
directive|define
name|PNG_READ_pHYs_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_sBIT_SUPPORTED
define|#
directive|define
name|PNG_READ_sBIT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_sCAL_SUPPORTED
define|#
directive|define
name|PNG_READ_sCAL_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_sPLT_SUPPORTED
define|#
directive|define
name|PNG_READ_sPLT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_sRGB_SUPPORTED
define|#
directive|define
name|PNG_READ_sRGB_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_tEXt_SUPPORTED
define|#
directive|define
name|PNG_READ_tEXt_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_tIME_SUPPORTED
define|#
directive|define
name|PNG_READ_tIME_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_tRNS_SUPPORTED
define|#
directive|define
name|PNG_READ_tRNS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_READ_zTXt_SUPPORTED
define|#
directive|define
name|PNG_READ_zTXt_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SAVE_INT_32_SUPPORTED
define|#
directive|define
name|PNG_SAVE_INT_32_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SEQUENTIAL_READ_SUPPORTED
define|#
directive|define
name|PNG_SEQUENTIAL_READ_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SETJMP_SUPPORTED
define|#
directive|define
name|PNG_SETJMP_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SET_CHUNK_CACHE_LIMIT_SUPPORTED
define|#
directive|define
name|PNG_SET_CHUNK_CACHE_LIMIT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SET_CHUNK_MALLOC_LIMIT_SUPPORTED
define|#
directive|define
name|PNG_SET_CHUNK_MALLOC_LIMIT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SET_OPTION_SUPPORTED
define|#
directive|define
name|PNG_SET_OPTION_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SET_USER_LIMITS_SUPPORTED
define|#
directive|define
name|PNG_SET_USER_LIMITS_SUPPORTED
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef
begin_define
DECL|macro|PNG_SIMPLIFIED_READ_AFIRST_SUPPORTED
define|#
directive|define
name|PNG_SIMPLIFIED_READ_AFIRST_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SIMPLIFIED_READ_BGR_SUPPORTED
define|#
directive|define
name|PNG_SIMPLIFIED_READ_BGR_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SIMPLIFIED_READ_SUPPORTED
define|#
directive|define
name|PNG_SIMPLIFIED_READ_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SIMPLIFIED_WRITE_AFIRST_SUPPORTED
define|#
directive|define
name|PNG_SIMPLIFIED_WRITE_AFIRST_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SIMPLIFIED_WRITE_BGR_SUPPORTED
define|#
directive|define
name|PNG_SIMPLIFIED_WRITE_BGR_SUPPORTED
end_define
begin_define
DECL|macro|PNG_SIMPLIFIED_WRITE_SUPPORTED
define|#
directive|define
name|PNG_SIMPLIFIED_WRITE_SUPPORTED
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|PNG_STDIO_SUPPORTED
define|#
directive|define
name|PNG_STDIO_SUPPORTED
end_define
begin_define
DECL|macro|PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_TEXT_SUPPORTED
define|#
directive|define
name|PNG_TEXT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_TIME_RFC1123_SUPPORTED
define|#
directive|define
name|PNG_TIME_RFC1123_SUPPORTED
end_define
begin_define
DECL|macro|PNG_UNKNOWN_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_UNKNOWN_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_USER_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_USER_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_USER_LIMITS_SUPPORTED
define|#
directive|define
name|PNG_USER_LIMITS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_USER_MEM_SUPPORTED
define|#
directive|define
name|PNG_USER_MEM_SUPPORTED
end_define
begin_define
DECL|macro|PNG_USER_TRANSFORM_INFO_SUPPORTED
define|#
directive|define
name|PNG_USER_TRANSFORM_INFO_SUPPORTED
end_define
begin_define
DECL|macro|PNG_USER_TRANSFORM_PTR_SUPPORTED
define|#
directive|define
name|PNG_USER_TRANSFORM_PTR_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WARNINGS_SUPPORTED
define|#
directive|define
name|PNG_WARNINGS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_16BIT_SUPPORTED
define|#
directive|define
name|PNG_WRITE_16BIT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_ANCILLARY_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_WRITE_ANCILLARY_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_BGR_SUPPORTED
define|#
directive|define
name|PNG_WRITE_BGR_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_CHECK_FOR_INVALID_INDEX_SUPPORTED
define|#
directive|define
name|PNG_WRITE_CHECK_FOR_INVALID_INDEX_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_COMPRESSED_TEXT_SUPPORTED
define|#
directive|define
name|PNG_WRITE_COMPRESSED_TEXT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED
define|#
directive|define
name|PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
define|#
directive|define
name|PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_FILLER_SUPPORTED
define|#
directive|define
name|PNG_WRITE_FILLER_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_FILTER_SUPPORTED
define|#
directive|define
name|PNG_WRITE_FILTER_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_FLUSH_SUPPORTED
define|#
directive|define
name|PNG_WRITE_FLUSH_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_GET_PALETTE_MAX_SUPPORTED
define|#
directive|define
name|PNG_WRITE_GET_PALETTE_MAX_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_INTERLACING_SUPPORTED
define|#
directive|define
name|PNG_WRITE_INTERLACING_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_INT_FUNCTIONS_SUPPORTED
define|#
directive|define
name|PNG_WRITE_INT_FUNCTIONS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_INVERT_ALPHA_SUPPORTED
define|#
directive|define
name|PNG_WRITE_INVERT_ALPHA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_INVERT_SUPPORTED
define|#
directive|define
name|PNG_WRITE_INVERT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_OPTIMIZE_CMF_SUPPORTED
define|#
directive|define
name|PNG_WRITE_OPTIMIZE_CMF_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_PACKSWAP_SUPPORTED
define|#
directive|define
name|PNG_WRITE_PACKSWAP_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_PACK_SUPPORTED
define|#
directive|define
name|PNG_WRITE_PACK_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_SHIFT_SUPPORTED
define|#
directive|define
name|PNG_WRITE_SHIFT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_SUPPORTED
define|#
directive|define
name|PNG_WRITE_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_SWAP_ALPHA_SUPPORTED
define|#
directive|define
name|PNG_WRITE_SWAP_ALPHA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_SWAP_SUPPORTED
define|#
directive|define
name|PNG_WRITE_SWAP_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_TEXT_SUPPORTED
define|#
directive|define
name|PNG_WRITE_TEXT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_TRANSFORMS_SUPPORTED
define|#
directive|define
name|PNG_WRITE_TRANSFORMS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
define|#
directive|define
name|PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_USER_TRANSFORM_SUPPORTED
define|#
directive|define
name|PNG_WRITE_USER_TRANSFORM_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_WEIGHTED_FILTER_SUPPORTED
define|#
directive|define
name|PNG_WRITE_WEIGHTED_FILTER_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_bKGD_SUPPORTED
define|#
directive|define
name|PNG_WRITE_bKGD_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_cHRM_SUPPORTED
define|#
directive|define
name|PNG_WRITE_cHRM_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_gAMA_SUPPORTED
define|#
directive|define
name|PNG_WRITE_gAMA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_hIST_SUPPORTED
define|#
directive|define
name|PNG_WRITE_hIST_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_iCCP_SUPPORTED
define|#
directive|define
name|PNG_WRITE_iCCP_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_iTXt_SUPPORTED
define|#
directive|define
name|PNG_WRITE_iTXt_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_oFFs_SUPPORTED
define|#
directive|define
name|PNG_WRITE_oFFs_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_pCAL_SUPPORTED
define|#
directive|define
name|PNG_WRITE_pCAL_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_pHYs_SUPPORTED
define|#
directive|define
name|PNG_WRITE_pHYs_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_sBIT_SUPPORTED
define|#
directive|define
name|PNG_WRITE_sBIT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_sCAL_SUPPORTED
define|#
directive|define
name|PNG_WRITE_sCAL_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_sPLT_SUPPORTED
define|#
directive|define
name|PNG_WRITE_sPLT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_sRGB_SUPPORTED
define|#
directive|define
name|PNG_WRITE_sRGB_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_tEXt_SUPPORTED
define|#
directive|define
name|PNG_WRITE_tEXt_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_tIME_SUPPORTED
define|#
directive|define
name|PNG_WRITE_tIME_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_tRNS_SUPPORTED
define|#
directive|define
name|PNG_WRITE_tRNS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_WRITE_zTXt_SUPPORTED
define|#
directive|define
name|PNG_WRITE_zTXt_SUPPORTED
end_define
begin_define
DECL|macro|PNG_bKGD_SUPPORTED
define|#
directive|define
name|PNG_bKGD_SUPPORTED
end_define
begin_define
DECL|macro|PNG_cHRM_SUPPORTED
define|#
directive|define
name|PNG_cHRM_SUPPORTED
end_define
begin_define
DECL|macro|PNG_gAMA_SUPPORTED
define|#
directive|define
name|PNG_gAMA_SUPPORTED
end_define
begin_define
DECL|macro|PNG_hIST_SUPPORTED
define|#
directive|define
name|PNG_hIST_SUPPORTED
end_define
begin_define
DECL|macro|PNG_iCCP_SUPPORTED
define|#
directive|define
name|PNG_iCCP_SUPPORTED
end_define
begin_define
DECL|macro|PNG_iTXt_SUPPORTED
define|#
directive|define
name|PNG_iTXt_SUPPORTED
end_define
begin_define
DECL|macro|PNG_oFFs_SUPPORTED
define|#
directive|define
name|PNG_oFFs_SUPPORTED
end_define
begin_define
DECL|macro|PNG_pCAL_SUPPORTED
define|#
directive|define
name|PNG_pCAL_SUPPORTED
end_define
begin_define
DECL|macro|PNG_pHYs_SUPPORTED
define|#
directive|define
name|PNG_pHYs_SUPPORTED
end_define
begin_define
DECL|macro|PNG_sBIT_SUPPORTED
define|#
directive|define
name|PNG_sBIT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_sCAL_SUPPORTED
define|#
directive|define
name|PNG_sCAL_SUPPORTED
end_define
begin_define
DECL|macro|PNG_sPLT_SUPPORTED
define|#
directive|define
name|PNG_sPLT_SUPPORTED
end_define
begin_define
DECL|macro|PNG_sRGB_SUPPORTED
define|#
directive|define
name|PNG_sRGB_SUPPORTED
end_define
begin_define
DECL|macro|PNG_tEXt_SUPPORTED
define|#
directive|define
name|PNG_tEXt_SUPPORTED
end_define
begin_define
DECL|macro|PNG_tIME_SUPPORTED
define|#
directive|define
name|PNG_tIME_SUPPORTED
end_define
begin_define
DECL|macro|PNG_tRNS_SUPPORTED
define|#
directive|define
name|PNG_tRNS_SUPPORTED
end_define
begin_define
DECL|macro|PNG_zTXt_SUPPORTED
define|#
directive|define
name|PNG_zTXt_SUPPORTED
end_define
begin_comment
comment|/* end of options */
end_comment
begin_comment
comment|/* settings */
end_comment
begin_define
DECL|macro|PNG_API_RULE
define|#
directive|define
name|PNG_API_RULE
value|0
end_define
begin_define
DECL|macro|PNG_COST_SHIFT
define|#
directive|define
name|PNG_COST_SHIFT
value|3
end_define
begin_define
DECL|macro|PNG_DEFAULT_READ_MACROS
define|#
directive|define
name|PNG_DEFAULT_READ_MACROS
value|1
end_define
begin_define
DECL|macro|PNG_GAMMA_THRESHOLD_FIXED
define|#
directive|define
name|PNG_GAMMA_THRESHOLD_FIXED
value|5000
end_define
begin_define
DECL|macro|PNG_IDAT_READ_SIZE
define|#
directive|define
name|PNG_IDAT_READ_SIZE
value|PNG_ZBUF_SIZE
end_define
begin_define
DECL|macro|PNG_INFLATE_BUF_SIZE
define|#
directive|define
name|PNG_INFLATE_BUF_SIZE
value|1024
end_define
begin_define
DECL|macro|PNG_LINKAGE_API
define|#
directive|define
name|PNG_LINKAGE_API
value|extern
end_define
begin_define
DECL|macro|PNG_LINKAGE_CALLBACK
define|#
directive|define
name|PNG_LINKAGE_CALLBACK
value|extern
end_define
begin_define
DECL|macro|PNG_LINKAGE_DATA
define|#
directive|define
name|PNG_LINKAGE_DATA
value|extern
end_define
begin_define
DECL|macro|PNG_LINKAGE_FUNCTION
define|#
directive|define
name|PNG_LINKAGE_FUNCTION
value|extern
end_define
begin_define
DECL|macro|PNG_MAX_GAMMA_8
define|#
directive|define
name|PNG_MAX_GAMMA_8
value|11
end_define
begin_define
DECL|macro|PNG_QUANTIZE_BLUE_BITS
define|#
directive|define
name|PNG_QUANTIZE_BLUE_BITS
value|5
end_define
begin_define
DECL|macro|PNG_QUANTIZE_GREEN_BITS
define|#
directive|define
name|PNG_QUANTIZE_GREEN_BITS
value|5
end_define
begin_define
DECL|macro|PNG_QUANTIZE_RED_BITS
define|#
directive|define
name|PNG_QUANTIZE_RED_BITS
value|5
end_define
begin_define
DECL|macro|PNG_TEXT_Z_DEFAULT_COMPRESSION
define|#
directive|define
name|PNG_TEXT_Z_DEFAULT_COMPRESSION
value|(-1)
end_define
begin_define
DECL|macro|PNG_TEXT_Z_DEFAULT_STRATEGY
define|#
directive|define
name|PNG_TEXT_Z_DEFAULT_STRATEGY
value|0
end_define
begin_define
DECL|macro|PNG_USER_CHUNK_CACHE_MAX
define|#
directive|define
name|PNG_USER_CHUNK_CACHE_MAX
value|1000
end_define
begin_define
DECL|macro|PNG_USER_CHUNK_MALLOC_MAX
define|#
directive|define
name|PNG_USER_CHUNK_MALLOC_MAX
value|8000000
end_define
begin_define
DECL|macro|PNG_USER_HEIGHT_MAX
define|#
directive|define
name|PNG_USER_HEIGHT_MAX
value|1000000
end_define
begin_define
DECL|macro|PNG_USER_WIDTH_MAX
define|#
directive|define
name|PNG_USER_WIDTH_MAX
value|1000000
end_define
begin_define
DECL|macro|PNG_WEIGHT_SHIFT
define|#
directive|define
name|PNG_WEIGHT_SHIFT
value|8
end_define
begin_define
DECL|macro|PNG_ZBUF_SIZE
define|#
directive|define
name|PNG_ZBUF_SIZE
value|8192
end_define
begin_define
DECL|macro|PNG_ZLIB_VERNUM
define|#
directive|define
name|PNG_ZLIB_VERNUM
value|0
end_define
begin_comment
DECL|macro|PNG_ZLIB_VERNUM
comment|/* unknown */
end_comment
begin_define
DECL|macro|PNG_Z_DEFAULT_COMPRESSION
define|#
directive|define
name|PNG_Z_DEFAULT_COMPRESSION
value|(-1)
end_define
begin_define
DECL|macro|PNG_Z_DEFAULT_NOFILTER_STRATEGY
define|#
directive|define
name|PNG_Z_DEFAULT_NOFILTER_STRATEGY
value|0
end_define
begin_define
DECL|macro|PNG_Z_DEFAULT_STRATEGY
define|#
directive|define
name|PNG_Z_DEFAULT_STRATEGY
value|1
end_define
begin_define
DECL|macro|PNG_sCAL_PRECISION
define|#
directive|define
name|PNG_sCAL_PRECISION
value|5
end_define
begin_define
DECL|macro|PNG_sRGB_PROFILE_CHECKS
define|#
directive|define
name|PNG_sRGB_PROFILE_CHECKS
value|2
end_define
begin_comment
comment|/* end of settings */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PNGLCONF_H */
end_comment
end_unit
