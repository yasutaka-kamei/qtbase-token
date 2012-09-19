begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTXUNITSTREAMER_P_H
end_ifndef
begin_define
DECL|macro|QTESTXUNITSTREAMER_P_H
define|#
directive|define
name|QTESTXUNITSTREAMER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QTestElement
name|class
name|QTestElement
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTestElementAttribute
name|class
name|QTestElementAttribute
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXunitTestLogger
name|class
name|QXunitTestLogger
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QTestCharBuffer
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QTestXunitStreamer
block|{
name|public
label|:
name|QTestXunitStreamer
argument_list|(
name|QXunitTestLogger
operator|*
name|logger
argument_list|)
expr_stmt|;
operator|~
name|QTestXunitStreamer
argument_list|()
expr_stmt|;
name|void
name|formatStart
argument_list|(
specifier|const
name|QTestElement
operator|*
name|element
argument_list|,
name|QTestCharBuffer
operator|*
name|formatted
argument_list|)
decl|const
decl_stmt|;
name|void
name|formatEnd
argument_list|(
specifier|const
name|QTestElement
operator|*
name|element
argument_list|,
name|QTestCharBuffer
operator|*
name|formatted
argument_list|)
decl|const
decl_stmt|;
name|void
name|formatAfterAttributes
argument_list|(
specifier|const
name|QTestElement
operator|*
name|element
argument_list|,
name|QTestCharBuffer
operator|*
name|formatted
argument_list|)
decl|const
decl_stmt|;
name|void
name|formatAttributes
argument_list|(
specifier|const
name|QTestElement
operator|*
name|element
argument_list|,
specifier|const
name|QTestElementAttribute
operator|*
name|attribute
argument_list|,
name|QTestCharBuffer
operator|*
name|formatted
argument_list|)
decl|const
decl_stmt|;
name|void
name|output
argument_list|(
name|QTestElement
operator|*
name|element
argument_list|)
decl|const
decl_stmt|;
name|void
name|outputElements
argument_list|(
name|QTestElement
operator|*
name|element
argument_list|,
name|bool
name|isChildElement
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|void
name|outputElementAttributes
argument_list|(
specifier|const
name|QTestElement
operator|*
name|element
argument_list|,
name|QTestElementAttribute
operator|*
name|attribute
argument_list|)
decl|const
decl_stmt|;
name|void
name|outputString
argument_list|(
specifier|const
name|char
operator|*
name|msg
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|displayXunitXmlHeader
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|void
name|indentForElement
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
name|QXunitTestLogger
modifier|*
name|testLogger
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
