begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CPPWRITEICONDECLARATION_H
end_ifndef
begin_define
DECL|macro|CPPWRITEICONDECLARATION_H
define|#
directive|define
name|CPPWRITEICONDECLARATION_H
end_define
begin_include
include|#
directive|include
file|"treewalker.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Driver
name|class
name|Driver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Uic
name|class
name|Uic
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|Option
struct_decl|;
end_struct_decl
begin_decl_stmt
name|namespace
name|CPP
block|{
name|class
name|WriteIconDeclaration
range|:
name|public
name|TreeWalker
block|{
name|public
operator|:
name|WriteIconDeclaration
argument_list|(
name|Uic
operator|*
name|uic
argument_list|)
block|;
name|void
name|acceptUI
argument_list|(
name|DomUI
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptImages
argument_list|(
name|DomImages
operator|*
name|images
argument_list|)
block|;
name|void
name|acceptImage
argument_list|(
name|DomImage
operator|*
name|image
argument_list|)
block|;
name|private
operator|:
name|Driver
operator|*
name|driver
block|;
name|QTextStream
operator|&
name|output
block|;
specifier|const
name|Option
operator|&
name|option
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace CPP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CPPWRITEICONDECLARATION_H
end_comment
end_unit
