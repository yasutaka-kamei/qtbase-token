begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QINPUTPANEL_H
end_ifndef
begin_define
DECL|macro|QINPUTPANEL_H
define|#
directive|define
name|QINPUTPANEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QInputPanelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QInputPanel
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QInputPanel
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QObject *inputItem READ inputItem WRITE setInputItem NOTIFY inputItemChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRectF cursorRect READ cursorRect NOTIFY cursorRectChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRectF keyboardRect READ keyboardRect NOTIFY keyboardRectChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool open READ isOpen WRITE setOpen NOTIFY openChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool animating READ isAnimating NOTIFY animatingChanged
argument_list|)
name|public
operator|:
name|QObject
operator|*
name|inputItem
argument_list|()
specifier|const
block|;
name|void
name|setInputItem
argument_list|(
name|QObject
operator|*
name|inputItemChanged
argument_list|)
block|;
comment|// the window containing the editor
name|QWindow
operator|*
name|inputWindow
argument_list|()
specifier|const
block|;
name|QTransform
name|inputItemTransform
argument_list|()
specifier|const
block|;
name|void
name|setInputItemTranform
argument_list|(
specifier|const
name|QTransform
operator|&
name|transform
argument_list|)
block|;
comment|// in window coordinates
name|QRectF
name|cursorRect
argument_list|()
specifier|const
block|;
comment|// ### what if we have rotations for the item?
comment|// keyboard geometry in window coords
name|QRectF
name|keyboardRect
argument_list|()
block|;      enum
name|Action
block|{
name|Click
block|,
name|ContextMenu
block|}
block|;
name|bool
name|isOpen
argument_list|()
specifier|const
block|;
name|void
name|setOpen
argument_list|(
argument|bool open
argument_list|)
block|;
name|bool
name|isAnimating
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|open
argument_list|()
block|;
name|void
name|close
argument_list|()
block|;
name|void
name|update
argument_list|(
argument|Qt::InputMethodQueries queries
argument_list|)
block|;
name|void
name|reset
argument_list|()
block|;
name|void
name|invokeAction
argument_list|(
argument|Action a
argument_list|,
argument|int cursorPosition
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|inputItemChanged
argument_list|()
block|;
name|void
name|cursorRectChanged
argument_list|()
block|;
name|void
name|keyboardRectChanged
argument_list|()
block|;
name|void
name|openChanged
argument_list|()
block|;
name|void
name|animatingChanged
argument_list|()
block|;
name|private
operator|:
name|friend
name|class
name|QGuiApplication
block|;
name|friend
name|class
name|QGuiApplicationPrivate
block|;
name|friend
name|class
name|QPlatformInputContext
block|;
name|QInputPanel
argument_list|()
block|;
operator|~
name|QInputPanel
argument_list|()
block|; }
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
end_unit
