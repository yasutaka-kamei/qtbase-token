begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTPRINTDIALOG_H
end_ifndef
begin_define
DECL|macro|QABSTRACTPRINTDIALOG_H
define|#
directive|define
name|QABSTRACTPRINTDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qdialog.h>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/qtprintsupportglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
DECL|variable|QAbstractPrintDialogPrivate
name|class
name|QAbstractPrintDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrinter
name|class
name|QPrinter
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ### QtPrintNG: merge this class with QPrintDialog
end_comment
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QAbstractPrintDialog
range|:
name|public
name|QDialog
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractPrintDialog
argument_list|)
name|Q_OBJECT
name|public
operator|:
comment|// Keep in sync with QPrinter::PrintRange
expr|enum
name|PrintRange
block|{
name|AllPages
block|,
name|Selection
block|,
name|PageRange
block|,
name|CurrentPage
block|}
block|;      enum
name|PrintDialogOption
block|{
name|None
operator|=
literal|0x0000
block|,
comment|// obsolete
name|PrintToFile
operator|=
literal|0x0001
block|,
name|PrintSelection
operator|=
literal|0x0002
block|,
name|PrintPageRange
operator|=
literal|0x0004
block|,
name|PrintShowPageSize
operator|=
literal|0x0008
block|,
name|PrintCollateCopies
operator|=
literal|0x0010
block|,
name|DontUseSheet
operator|=
literal|0x0020
block|,
name|PrintCurrentPage
operator|=
literal|0x0040
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|PrintDialogOptions
argument_list|,
argument|PrintDialogOption
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
name|explicit
name|QAbstractPrintDialog
argument_list|(
name|QPrinter
operator|*
name|printer
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QAbstractPrintDialog
argument_list|()
block|;
name|virtual
name|int
name|exec
argument_list|()
operator|=
literal|0
block|;
comment|// obsolete
name|void
name|addEnabledOption
argument_list|(
argument|PrintDialogOption option
argument_list|)
block|;
name|void
name|setEnabledOptions
argument_list|(
argument|PrintDialogOptions options
argument_list|)
block|;
name|PrintDialogOptions
name|enabledOptions
argument_list|()
specifier|const
block|;
name|bool
name|isOptionEnabled
argument_list|(
argument|PrintDialogOption option
argument_list|)
specifier|const
block|;
name|void
name|setOptionTabs
argument_list|(
specifier|const
name|QList
operator|<
name|QWidget
operator|*
operator|>
operator|&
name|tabs
argument_list|)
block|;
name|void
name|setPrintRange
argument_list|(
argument|PrintRange range
argument_list|)
block|;
name|PrintRange
name|printRange
argument_list|()
specifier|const
block|;
name|void
name|setMinMax
argument_list|(
argument|int min
argument_list|,
argument|int max
argument_list|)
block|;
name|int
name|minPage
argument_list|()
specifier|const
block|;
name|int
name|maxPage
argument_list|()
specifier|const
block|;
name|void
name|setFromTo
argument_list|(
argument|int fromPage
argument_list|,
argument|int toPage
argument_list|)
block|;
name|int
name|fromPage
argument_list|()
specifier|const
block|;
name|int
name|toPage
argument_list|()
specifier|const
block|;
name|QPrinter
operator|*
name|printer
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QAbstractPrintDialog
argument_list|(
name|QAbstractPrintDialogPrivate
operator|&
name|ptr
argument_list|,
name|QPrinter
operator|*
name|printer
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractPrintDialog
argument_list|)
endif|#
directive|endif
comment|// QT_NO_PRINTDIALOG
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAbstractPrintDialog::PrintDialogOptions
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTPRINTDIALOG_H
end_comment
end_unit
