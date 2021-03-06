begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSGLOBAL_H
end_ifndef
begin_define
DECL|macro|QEGLFSGLOBAL_H
define|#
directive|define
name|QEGLFSGLOBAL_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUILD_EGL_DEVICE_LIB
end_ifdef
begin_define
DECL|macro|Q_EGLFS_EXPORT
define|#
directive|define
name|Q_EGLFS_EXPORT
value|Q_DECL_EXPORT
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_EGLFS_EXPORT
define|#
directive|define
name|Q_EGLFS_EXPORT
value|Q_DECL_IMPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_undef
DECL|macro|Status
undef|#
directive|undef
name|Status
end_undef
begin_undef
DECL|macro|None
undef|#
directive|undef
name|None
end_undef
begin_undef
DECL|macro|Bool
undef|#
directive|undef
name|Bool
end_undef
begin_undef
DECL|macro|CursorShape
undef|#
directive|undef
name|CursorShape
end_undef
begin_undef
DECL|macro|KeyPress
undef|#
directive|undef
name|KeyPress
end_undef
begin_undef
DECL|macro|KeyRelease
undef|#
directive|undef
name|KeyRelease
end_undef
begin_undef
DECL|macro|FocusIn
undef|#
directive|undef
name|FocusIn
end_undef
begin_undef
DECL|macro|FocusOut
undef|#
directive|undef
name|FocusOut
end_undef
begin_undef
DECL|macro|FontChange
undef|#
directive|undef
name|FontChange
end_undef
begin_undef
DECL|macro|Expose
undef|#
directive|undef
name|Expose
end_undef
begin_undef
DECL|macro|Unsorted
undef|#
directive|undef
name|Unsorted
end_undef
begin_endif
endif|#
directive|endif
end_endif
end_unit
