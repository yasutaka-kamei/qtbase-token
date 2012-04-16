begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|INPUTMETHODHINTS_H
end_ifndef
begin_define
DECL|macro|INPUTMETHODHINTS_H
define|#
directive|define
name|INPUTMETHODHINTS_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/QMainWindow>
end_include
begin_include
include|#
directive|include
file|"ui_inputmethodhints.h"
end_include
begin_decl_stmt
name|class
name|inputmethodhints
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|inputmethodhints
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|inputmethodhints
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|checkboxChanged
argument_list|(
name|int
argument_list|)
block|;
name|private
operator|:
name|Ui
operator|::
name|MainWindow
name|ui
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// INPUTMETHODHINTS_H
end_comment
end_unit
