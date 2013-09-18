begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAGESETUPDIALOG_UNIX_P_H
end_ifndef
begin_define
DECL|macro|QPAGESETUPDIALOG_UNIX_P_H
define|#
directive|define
name|QPAGESETUPDIALOG_UNIX_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
end_ifndef
begin_include
include|#
directive|include
file|<ui_qpagesetupwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPrinter
name|class
name|QPrinter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPagePreview
name|class
name|QPagePreview
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPageSetupWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QPageSetupWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QPageSetupWidget
argument_list|(
name|QPrinter
operator|*
name|printer
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setPrinter
argument_list|(
name|QPrinter
operator|*
name|printer
argument_list|)
block|;
comment|/// copy information from the widget and apply that to the printer.
name|void
name|setupPrinter
argument_list|()
specifier|const
block|;
name|void
name|selectPrinter
argument_list|()
block|;
name|void
name|selectPdfPsPrinter
argument_list|(
specifier|const
name|QPrinter
operator|*
name|p
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|_q_pageOrientationChanged
argument_list|()
block|;
name|void
name|_q_paperSizeChanged
argument_list|()
block|;
name|void
name|_q_pagesPerSheetChanged
argument_list|()
block|;
name|void
name|unitChanged
argument_list|(
argument|int item
argument_list|)
block|;
name|void
name|setTopMargin
argument_list|(
argument|double newValue
argument_list|)
block|;
name|void
name|setBottomMargin
argument_list|(
argument|double newValue
argument_list|)
block|;
name|void
name|setLeftMargin
argument_list|(
argument|double newValue
argument_list|)
block|;
name|void
name|setRightMargin
argument_list|(
argument|double newValue
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QUnixPrintWidgetPrivate
block|;
name|Ui
operator|::
name|QPageSetupWidget
name|widget
block|;
name|QPagePreview
operator|*
name|m_pagePreview
block|;
name|QPrinter
operator|*
name|m_printer
block|;
name|qreal
name|m_leftMargin
block|;
name|qreal
name|m_topMargin
block|;
name|qreal
name|m_rightMargin
block|;
name|qreal
name|m_bottomMargin
block|;
name|QSizeF
name|m_paperSize
block|;
name|qreal
name|m_currentMultiplier
block|;
name|bool
name|m_blockSignals
block|;
name|bool
name|m_cups
block|;
name|void
name|initPagesPerSheet
argument_list|()
block|; }
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
comment|// QT_NO_PRINTDIALOG
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
