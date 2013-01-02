begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEMPORARYDIR_H
end_ifndef
begin_define
DECL|macro|QTEMPORARYDIR_H
define|#
directive|define
name|QTEMPORARYDIR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TEMPORARYFILE
DECL|variable|QTemporaryDirPrivate
name|class
name|QTemporaryDirPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTemporaryDir
block|{
name|public
label|:
name|QTemporaryDir
argument_list|()
expr_stmt|;
name|explicit
name|QTemporaryDir
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|)
function_decl|;
operator|~
name|QTemporaryDir
argument_list|()
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|autoRemove
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAutoRemove
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|bool
name|remove
parameter_list|()
function_decl|;
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QScopedPointer
operator|<
name|QTemporaryDirPrivate
operator|>
name|d_ptr
expr_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QTemporaryDir
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEMPORARYFILE
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEMPORARYDIR_H
end_comment
end_unit
