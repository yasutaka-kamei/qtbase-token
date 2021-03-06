begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_C89_QPLATFORMDEFS_H
end_ifndef
begin_define
DECL|macro|Q_C89_QPLATFORMDEFS_H
define|#
directive|define
name|Q_C89_QPLATFORMDEFS_H
end_define
begin_comment
comment|// #include<stdio.h>
end_comment
begin_define
DECL|macro|QT_FPOS_T
define|#
directive|define
name|QT_FPOS_T
value|fpos_t
end_define
begin_define
DECL|macro|QT_OFF_T
define|#
directive|define
name|QT_OFF_T
value|long
end_define
begin_define
DECL|macro|QT_FOPEN
define|#
directive|define
name|QT_FOPEN
value|::fopen
end_define
begin_define
DECL|macro|QT_FSEEK
define|#
directive|define
name|QT_FSEEK
value|::fseek
end_define
begin_define
DECL|macro|QT_FTELL
define|#
directive|define
name|QT_FTELL
value|::ftell
end_define
begin_define
DECL|macro|QT_FGETPOS
define|#
directive|define
name|QT_FGETPOS
value|::fgetpos
end_define
begin_define
DECL|macro|QT_FSETPOS
define|#
directive|define
name|QT_FSETPOS
value|::fsetpos
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// include guard
end_comment
end_unit
