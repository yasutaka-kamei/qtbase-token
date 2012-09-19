begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EMBEDDEDDIALOG_H
end_ifndef
begin_define
DECL|macro|EMBEDDEDDIALOG_H
define|#
directive|define
name|EMBEDDEDDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qdialog.h>
end_include
begin_expr_stmt
DECL|variable|Ui_embeddedDialog
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|Ui_embeddedDialog
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|EmbeddedDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|EmbeddedDialog
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|EmbeddedDialog
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|layoutDirectionChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|spacingChanged
argument_list|(
argument|int spacing
argument_list|)
block|;
name|void
name|fontChanged
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|void
name|styleChanged
argument_list|(
specifier|const
name|QString
operator|&
name|styleName
argument_list|)
block|;
name|private
operator|:
name|Ui_embeddedDialog
operator|*
name|ui
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
