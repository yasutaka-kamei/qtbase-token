begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright(c) 2014 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// export.h : Defines ANGLE_EXPORT, a macro for exporting functions from the DLL
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_EXPORT_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_EXPORT_H_
define|#
directive|define
name|LIBGLESV2_EXPORT_H_
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBGLESV2_IMPLEMENTATION
argument_list|)
operator|||
name|defined
argument_list|(
name|LIBANGLE_IMPLEMENTATION
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_EXPORT
define|#
directive|define
name|ANGLE_EXPORT
value|__declspec(dllexport)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ANGLE_EXPORT
define|#
directive|define
name|ANGLE_EXPORT
value|__declspec(dllimport)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBGLESV2_IMPLEMENTATION
argument_list|)
operator|||
name|defined
argument_list|(
name|LIBANGLE_IMPLEMENTATION
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_EXPORT
define|#
directive|define
name|ANGLE_EXPORT
value|__attribute__((visibility ("default")))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ANGLE_EXPORT
define|#
directive|define
name|ANGLE_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ANGLE_EXPORT
define|#
directive|define
name|ANGLE_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_EXPORT_H_
end_comment
end_unit