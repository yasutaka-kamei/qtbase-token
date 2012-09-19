begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSPLASHSCREEN_H
end_ifndef
begin_define
DECL|macro|QSPLASHSCREEN_H
define|#
directive|define
name|QSPLASHSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SPLASHSCREEN
DECL|variable|QSplashScreenPrivate
name|class
name|QSplashScreenPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QSplashScreen
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QSplashScreen
argument_list|(
argument|const QPixmap&pixmap = QPixmap()
argument_list|,
argument|Qt::WindowFlags f =
literal|0
argument_list|)
block|;
name|QSplashScreen
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QPixmap&pixmap = QPixmap()
argument_list|,
argument|Qt::WindowFlags f =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QSplashScreen
argument_list|()
block|;
name|void
name|setPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
block|;
specifier|const
name|QPixmap
name|pixmap
argument_list|()
specifier|const
block|;
name|void
name|finish
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|void
name|repaint
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|showMessage
argument_list|(
argument|const QString&message
argument_list|,
argument|int alignment = Qt::AlignLeft
argument_list|,
argument|const QColor&color = Qt::black
argument_list|)
block|;
name|void
name|clearMessage
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|messageChanged
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|drawContents
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSplashScreen
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSplashScreen
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SPLASHSCREEN
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
comment|// QSPLASHSCREEN_H
end_comment
end_unit
