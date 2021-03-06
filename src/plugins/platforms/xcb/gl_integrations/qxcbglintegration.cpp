begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbglintegration.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcQpaGl
argument_list|,
literal|"qt.qpa.gl"
argument_list|)
DECL|function|QXcbGlIntegration
name|QXcbGlIntegration
operator|::
name|QXcbGlIntegration
argument_list|()
argument_list|{ }
DECL|function|~QXcbGlIntegration
name|QXcbGlIntegration
operator|::
name|~
name|QXcbGlIntegration
argument_list|()
argument_list|{ }
DECL|function|handleXcbEvent
name|bool
name|QXcbGlIntegration
operator|::
name|handleXcbEvent
argument_list|(
name|xcb_generic_event_t
operator|*
name|event
argument_list|,
name|uint
name|responseType
argument_list|)
argument_list|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
argument_list|;
name|Q_UNUSED
argument_list|(
name|responseType
argument_list|)
argument_list|;     return
literal|false
argument_list|; }
name|QT_END_NAMESPACE
end_decl_stmt
end_unit
