begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIALOG_H
end_ifndef
begin_define
DECL|macro|QDIALOG_H
define|#
directive|define
name|QDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDialogPrivate
name|class
name|QDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDialog
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|friend
name|class
name|QPushButton
block|;
name|Q_PROPERTY
argument_list|(
argument|bool sizeGripEnabled READ isSizeGripEnabled WRITE setSizeGripEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool modal READ isModal WRITE setModal
argument_list|)
name|public
operator|:
name|explicit
name|QDialog
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags f =
literal|0
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|QT3_SUPPORT_CONSTRUCTOR
name|QDialog
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const char *name
argument_list|,
argument|bool modal = false
argument_list|,
argument|Qt::WindowFlags f =
literal|0
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QDialog
argument_list|()
block|;      enum
name|DialogCode
block|{
name|Rejected
block|,
name|Accepted
block|}
block|;
name|int
name|result
argument_list|()
specifier|const
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setOrientation
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
name|void
name|setExtension
argument_list|(
name|QWidget
operator|*
name|extension
argument_list|)
block|;
name|QWidget
operator|*
name|extension
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|void
name|setSizeGripEnabled
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isSizeGripEnabled
argument_list|()
specifier|const
block|;
name|void
name|setModal
argument_list|(
argument|bool modal
argument_list|)
block|;
name|void
name|setResult
argument_list|(
argument|int r
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|finished
argument_list|(
argument|int result
argument_list|)
block|;
name|void
name|accepted
argument_list|()
block|;
name|void
name|rejected
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|open
argument_list|()
block|;
name|int
name|exec
argument_list|()
block|;
name|virtual
name|void
name|done
argument_list|(
name|int
argument_list|)
block|;
name|virtual
name|void
name|accept
argument_list|()
block|;
name|virtual
name|void
name|reject
argument_list|()
block|;
name|void
name|showExtension
argument_list|(
name|bool
argument_list|)
block|;
name|protected
operator|:
name|QDialog
argument_list|(
argument|QDialogPrivate&
argument_list|,
argument|QWidget *parent
argument_list|,
argument|Qt::WindowFlags f =
literal|0
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|closeEvent
argument_list|(
name|QCloseEvent
operator|*
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|adjustPosition
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDialog
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QDialog
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|bool
name|symbianAdjustedPosition
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_WS_WINCE_WM
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_doneAction()
argument_list|)
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIALOG_H
end_comment
end_unit
