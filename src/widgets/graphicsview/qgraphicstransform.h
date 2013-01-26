begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSTRANSFORM_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSTRANSFORM_H
define|#
directive|define
name|QGRAPHICSTRANSFORM_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtGui/QVector3D>
end_include
begin_include
include|#
directive|include
file|<QtGui/QTransform>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMatrix4x4>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsTransformPrivate
name|class
name|QGraphicsTransformPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsTransform
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QGraphicsTransform
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsTransform
argument_list|()
block|;
name|virtual
name|void
name|applyTo
argument_list|(
argument|QMatrix4x4 *matrix
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|update
argument_list|()
block|;
name|protected
operator|:
name|QGraphicsTransform
argument_list|(
name|QGraphicsTransformPrivate
operator|&
name|p
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QGraphicsItem
block|;
name|friend
name|class
name|QGraphicsItemPrivate
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsTransform
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsScalePrivate
name|class
name|QGraphicsScalePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsScale
range|:
name|public
name|QGraphicsTransform
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QVector3D origin READ origin WRITE setOrigin NOTIFY originChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal xScale READ xScale WRITE setXScale NOTIFY xScaleChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal yScale READ yScale WRITE setYScale NOTIFY yScaleChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal zScale READ zScale WRITE setZScale NOTIFY zScaleChanged
argument_list|)
name|public
operator|:
name|QGraphicsScale
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsScale
argument_list|()
block|;
name|QVector3D
name|origin
argument_list|()
specifier|const
block|;
name|void
name|setOrigin
argument_list|(
specifier|const
name|QVector3D
operator|&
name|point
argument_list|)
block|;
name|qreal
name|xScale
argument_list|()
specifier|const
block|;
name|void
name|setXScale
argument_list|(
name|qreal
argument_list|)
block|;
name|qreal
name|yScale
argument_list|()
specifier|const
block|;
name|void
name|setYScale
argument_list|(
name|qreal
argument_list|)
block|;
name|qreal
name|zScale
argument_list|()
specifier|const
block|;
name|void
name|setZScale
argument_list|(
name|qreal
argument_list|)
block|;
name|void
name|applyTo
argument_list|(
argument|QMatrix4x4 *matrix
argument_list|)
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|originChanged
argument_list|()
block|;
name|void
name|xScaleChanged
argument_list|()
block|;
name|void
name|yScaleChanged
argument_list|()
block|;
name|void
name|zScaleChanged
argument_list|()
block|;
name|void
name|scaleChanged
argument_list|()
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsScale
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsRotationPrivate
name|class
name|QGraphicsRotationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsRotation
range|:
name|public
name|QGraphicsTransform
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QVector3D origin READ origin WRITE setOrigin NOTIFY originChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal angle READ angle WRITE setAngle NOTIFY angleChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QVector3D axis READ axis WRITE setAxis NOTIFY axisChanged
argument_list|)
name|public
operator|:
name|QGraphicsRotation
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsRotation
argument_list|()
block|;
name|QVector3D
name|origin
argument_list|()
specifier|const
block|;
name|void
name|setOrigin
argument_list|(
specifier|const
name|QVector3D
operator|&
name|point
argument_list|)
block|;
name|qreal
name|angle
argument_list|()
specifier|const
block|;
name|void
name|setAngle
argument_list|(
name|qreal
argument_list|)
block|;
name|QVector3D
name|axis
argument_list|()
specifier|const
block|;
name|void
name|setAxis
argument_list|(
specifier|const
name|QVector3D
operator|&
name|axis
argument_list|)
block|;
name|void
name|setAxis
argument_list|(
argument|Qt::Axis axis
argument_list|)
block|;
name|void
name|applyTo
argument_list|(
argument|QMatrix4x4 *matrix
argument_list|)
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|originChanged
argument_list|()
block|;
name|void
name|angleChanged
argument_list|()
block|;
name|void
name|axisChanged
argument_list|()
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsRotation
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
comment|//QT_NO_GRAPHICSVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFXTRANSFORM_H
end_comment
end_unit
