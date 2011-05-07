begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTPREVIEWWIDGET_H
end_ifndef
begin_define
DECL|macro|QPRINTPREVIEWWIDGET_H
define|#
directive|define
name|QPRINTPREVIEWWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qprinter.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTPREVIEWWIDGET
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QPrintPreviewWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPrintPreviewWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPrintPreviewWidget
argument_list|)
name|public
operator|:
expr|enum
name|ViewMode
block|{
name|SinglePageView
block|,
name|FacingPagesView
block|,
name|AllPagesView
block|}
block|;      enum
name|ZoomMode
block|{
name|CustomZoom
block|,
name|FitToWidth
block|,
name|FitInView
block|}
block|;
name|explicit
name|QPrintPreviewWidget
argument_list|(
argument|QPrinter *printer
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
name|explicit
name|QPrintPreviewWidget
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
operator|~
name|QPrintPreviewWidget
argument_list|()
block|;
name|qreal
name|zoomFactor
argument_list|()
specifier|const
block|;
name|QPrinter
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
name|ViewMode
name|viewMode
argument_list|()
specifier|const
block|;
name|ZoomMode
name|zoomMode
argument_list|()
specifier|const
block|;
name|int
name|currentPage
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT_DEPRECATED
name|QT_DEPRECATED
name|int
name|numPages
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|int
name|pageCount
argument_list|()
specifier|const
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|print
argument_list|()
block|;
name|void
name|zoomIn
argument_list|(
argument|qreal zoom =
literal|1.1
argument_list|)
block|;
name|void
name|zoomOut
argument_list|(
argument|qreal zoom =
literal|1.1
argument_list|)
block|;
name|void
name|setZoomFactor
argument_list|(
argument|qreal zoomFactor
argument_list|)
block|;
name|void
name|setOrientation
argument_list|(
argument|QPrinter::Orientation orientation
argument_list|)
block|;
name|void
name|setViewMode
argument_list|(
argument|ViewMode viewMode
argument_list|)
block|;
name|void
name|setZoomMode
argument_list|(
argument|ZoomMode zoomMode
argument_list|)
block|;
name|void
name|setCurrentPage
argument_list|(
argument|int pageNumber
argument_list|)
block|;
name|void
name|fitToWidth
argument_list|()
block|;
name|void
name|fitInView
argument_list|()
block|;
name|void
name|setLandscapeOrientation
argument_list|()
block|;
name|void
name|setPortraitOrientation
argument_list|()
block|;
name|void
name|setSinglePageViewMode
argument_list|()
block|;
name|void
name|setFacingPagesViewMode
argument_list|()
block|;
name|void
name|setAllPagesViewMode
argument_list|()
block|;
name|void
name|updatePreview
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|paintRequested
argument_list|(
name|QPrinter
operator|*
name|printer
argument_list|)
block|;
name|void
name|previewChanged
argument_list|()
block|;
name|private
operator|:
name|void
operator|*
name|dummy
block|;
comment|// ### remove in Qt 5.0
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_fit()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateCurrentPage()
argument_list|)
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
comment|// QT_NO_PRINTPREVIEWWIDGET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTPREVIEWWIDGET_H
end_comment
end_unit
