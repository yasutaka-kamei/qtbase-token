begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFRAME_H
end_ifndef
begin_define
DECL|macro|QFRAME_H
define|#
directive|define
name|QFRAME_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFramePrivate
name|class
name|QFramePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QFrame
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|Shape Shadow
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Shape frameShape READ frameShape WRITE setFrameShape
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Shadow frameShadow READ frameShadow WRITE setFrameShadow
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int lineWidth READ lineWidth WRITE setLineWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int midLineWidth READ midLineWidth WRITE setMidLineWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int frameWidth READ frameWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRect frameRect READ frameRect WRITE setFrameRect DESIGNABLE false
argument_list|)
name|public
operator|:
name|explicit
name|QFrame
argument_list|(
argument|QWidget* parent =
literal|0
argument_list|,
argument|Qt::WindowFlags f =
literal|0
argument_list|)
block|;
operator|~
name|QFrame
argument_list|()
block|;
name|int
name|frameStyle
argument_list|()
specifier|const
block|;
name|void
name|setFrameStyle
argument_list|(
name|int
argument_list|)
block|;
name|int
name|frameWidth
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;      enum
name|Shape
block|{
name|NoFrame
operator|=
literal|0
block|,
comment|// no frame
name|Box
operator|=
literal|0x0001
block|,
comment|// rectangular box
name|Panel
operator|=
literal|0x0002
block|,
comment|// rectangular panel
name|WinPanel
operator|=
literal|0x0003
block|,
comment|// rectangular panel (Windows)
name|HLine
operator|=
literal|0x0004
block|,
comment|// horizontal line
name|VLine
operator|=
literal|0x0005
block|,
comment|// vertical line
name|StyledPanel
operator|=
literal|0x0006
comment|// rectangular panel depending on the GUI style
block|}
block|;     enum
name|Shadow
block|{
name|Plain
operator|=
literal|0x0010
block|,
comment|// plain line
name|Raised
operator|=
literal|0x0020
block|,
comment|// raised shadow effect
name|Sunken
operator|=
literal|0x0030
comment|// sunken shadow effect
block|}
block|;      enum
name|StyleMask
block|{
name|Shadow_Mask
operator|=
literal|0x00f0
block|,
comment|// mask for the shadow
name|Shape_Mask
operator|=
literal|0x000f
comment|// mask for the shape
block|}
block|;
name|Shape
name|frameShape
argument_list|()
specifier|const
block|;
name|void
name|setFrameShape
argument_list|(
name|Shape
argument_list|)
block|;
name|Shadow
name|frameShadow
argument_list|()
specifier|const
block|;
name|void
name|setFrameShadow
argument_list|(
name|Shadow
argument_list|)
block|;
name|int
name|lineWidth
argument_list|()
specifier|const
block|;
name|void
name|setLineWidth
argument_list|(
name|int
argument_list|)
block|;
name|int
name|midLineWidth
argument_list|()
specifier|const
block|;
name|void
name|setMidLineWidth
argument_list|(
name|int
argument_list|)
block|;
name|QRect
name|frameRect
argument_list|()
specifier|const
block|;
name|void
name|setFrameRect
argument_list|(
specifier|const
name|QRect
operator|&
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
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|drawFrame
argument_list|(
name|QPainter
operator|*
argument_list|)
block|;
name|protected
operator|:
name|QFrame
argument_list|(
argument|QFramePrivate&dd
argument_list|,
argument|QWidget* parent =
literal|0
argument_list|,
argument|Qt::WindowFlags f =
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QFrame
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFrame
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFRAME_H
end_comment
end_unit
