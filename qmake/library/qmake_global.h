begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMAKE_GLOBAL_H
end_ifndef
begin_define
DECL|macro|QMAKE_GLOBAL_H
define|#
directive|define
name|QMAKE_GLOBAL_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QMAKE_AS_LIBRARY
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QMAKE_LIBRARY
argument_list|)
end_if
begin_define
DECL|macro|QMAKE_EXPORT
define|#
directive|define
name|QMAKE_EXPORT
value|Q_DECL_EXPORT
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QMAKE_EXPORT
define|#
directive|define
name|QMAKE_EXPORT
value|Q_DECL_IMPORT
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
DECL|macro|QMAKE_EXPORT
define|#
directive|define
name|QMAKE_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Be fast even for debug builds
end_comment
begin_comment
comment|// MinGW GCC 4.5+ has a problem with always_inline putTok and putBlockLen
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|5
operator|)
end_if
begin_define
DECL|macro|ALWAYS_INLINE
define|#
directive|define
name|ALWAYS_INLINE
value|inline __attribute__((always_inline))
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif
begin_define
DECL|macro|ALWAYS_INLINE
define|#
directive|define
name|ALWAYS_INLINE
value|__forceinline
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ALWAYS_INLINE
define|#
directive|define
name|ALWAYS_INLINE
value|inline
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
