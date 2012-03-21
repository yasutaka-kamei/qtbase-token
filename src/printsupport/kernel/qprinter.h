begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTER_H
end_ifndef
begin_define
DECL|macro|QPRINTER_H
define|#
directive|define
name|QPRINTER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagedpaintdevice.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
if|#
directive|if
name|defined
argument_list|(
name|B0
argument_list|)
DECL|macro|B0
undef|#
directive|undef
name|B0
comment|// Terminal hang-up.  We assume that you do not want that.
endif|#
directive|endif
DECL|variable|QPrinterPrivate
name|class
name|QPrinterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintEngine
name|class
name|QPaintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrintEngine
name|class
name|QPrintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrinterInfo
name|class
name|QPrinterInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPrinter
range|:
name|public
name|QPagedPaintDevice
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPrinter
argument_list|)
name|public
operator|:
expr|enum
name|PrinterMode
block|{
name|ScreenResolution
block|,
name|PrinterResolution
block|,
name|HighResolution
block|}
block|;
name|explicit
name|QPrinter
argument_list|(
argument|PrinterMode mode = ScreenResolution
argument_list|)
block|;
name|explicit
name|QPrinter
argument_list|(
argument|const QPrinterInfo& printer
argument_list|,
argument|PrinterMode mode = ScreenResolution
argument_list|)
block|;
operator|~
name|QPrinter
argument_list|()
block|;
name|int
name|devType
argument_list|()
specifier|const
block|;      enum
name|Orientation
block|{
name|Portrait
block|,
name|Landscape
block|}
block|;
ifndef|#
directive|ifndef
name|Q_QDOC
typedef|typedef
name|PageSize
name|PaperSize
typedef|;
else|#
directive|else
block|enum
name|PaperSize
block|{
name|A4
block|,
name|B5
block|,
name|Letter
block|,
name|Legal
block|,
name|Executive
block|,
name|A0
block|,
name|A1
block|,
name|A2
block|,
name|A3
block|,
name|A5
block|,
name|A6
block|,
name|A7
block|,
name|A8
block|,
name|A9
block|,
name|B0
block|,
name|B1
block|,
name|B10
block|,
name|B2
block|,
name|B3
block|,
name|B4
block|,
name|B6
block|,
name|B7
block|,
name|B8
block|,
name|B9
block|,
name|C5E
block|,
name|Comm10E
block|,
name|DLE
block|,
name|Folio
block|,
name|Ledger
block|,
name|Tabloid
block|,
name|Custom
block|,
name|NPageSize
operator|=
name|Custom
block|,
name|NPaperSize
operator|=
name|Custom
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_enum
enum|enum
name|PageOrder
block|{
name|FirstPageFirst
block|,
name|LastPageFirst
block|}
enum|;
end_enum
begin_enum
enum|enum
name|ColorMode
block|{
name|GrayScale
block|,
name|Color
block|}
enum|;
end_enum
begin_enum
enum|enum
name|PaperSource
block|{
name|OnlyOne
block|,
name|Lower
block|,
name|Middle
block|,
name|Manual
block|,
name|Envelope
block|,
name|EnvelopeManual
block|,
name|Auto
block|,
name|Tractor
block|,
name|SmallFormat
block|,
name|LargeFormat
block|,
name|LargeCapacity
block|,
name|Cassette
block|,
name|FormSource
block|,
name|MaxPageSource
block|}
enum|;
end_enum
begin_enum
enum|enum
name|PrinterState
block|{
name|Idle
block|,
name|Active
block|,
name|Aborted
block|,
name|Error
block|}
enum|;
end_enum
begin_enum
enum|enum
name|OutputFormat
block|{
name|NativeFormat
block|,
name|PdfFormat
block|}
enum|;
end_enum
begin_comment
comment|// Keep in sync with QAbstractPrintDialog::PrintRange
end_comment
begin_enum
enum|enum
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
enum|;
end_enum
begin_enum
enum|enum
name|Unit
block|{
name|Millimeter
block|,
name|Point
block|,
name|Inch
block|,
name|Pica
block|,
name|Didot
block|,
name|Cicero
block|,
name|DevicePixel
block|}
enum|;
end_enum
begin_enum
enum|enum
name|DuplexMode
block|{
name|DuplexNone
init|=
literal|0
block|,
name|DuplexAuto
block|,
name|DuplexLongSide
block|,
name|DuplexShortSide
block|}
enum|;
end_enum
begin_function_decl
name|void
name|setOutputFormat
parameter_list|(
name|OutputFormat
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|OutputFormat
name|outputFormat
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPrinterName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|printerName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setOutputFileName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|outputFileName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPrintProgram
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|printProgram
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDocName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|docName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setCreator
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|creator
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setOrientation
parameter_list|(
name|Orientation
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Orientation
name|orientation
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPageSize
parameter_list|(
name|PageSize
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|PageSize
name|pageSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPageSizeMM
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setPaperSize
parameter_list|(
name|PaperSize
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|PaperSize
name|paperSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPaperSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|paperSize
parameter_list|,
name|Unit
name|unit
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QSizeF
name|paperSize
argument_list|(
name|Unit
name|unit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setPageOrder
parameter_list|(
name|PageOrder
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|PageOrder
name|pageOrder
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setResolution
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|resolution
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setColorMode
parameter_list|(
name|ColorMode
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|ColorMode
name|colorMode
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setCollateCopies
parameter_list|(
name|bool
name|collate
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|collateCopies
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFullPage
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|fullPage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setNumCopies
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|numCopies
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|actualNumCopies
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setCopyCount
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|copyCount
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|supportsMultipleCopies
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPaperSource
parameter_list|(
name|PaperSource
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|PaperSource
name|paperSource
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDuplex
parameter_list|(
name|DuplexMode
name|duplex
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|DuplexMode
name|duplex
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|int
operator|>
name|supportedResolutions
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_expr_stmt
name|QList
operator|<
name|PaperSource
operator|>
name|supportedPaperSources
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|setFontEmbeddingEnabled
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|fontEmbeddingEnabled
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDoubleSidedPrinting
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|doubleSidedPrinting
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_function_decl
name|void
name|setWinPageSize
parameter_list|(
name|int
name|winPageSize
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|winPageSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QRect
name|paperRect
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QRect
name|pageRect
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QRectF
name|paperRect
argument_list|(
name|Unit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRectF
name|pageRect
argument_list|(
name|Unit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|qdoc
argument_list|)
end_if
begin_expr_stmt
name|QString
name|printerSelectionOption
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPrinterSelectionOption
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|bool
name|newPage
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|abort
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|PrinterState
name|printerState
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPrintEngine
operator|*
name|printEngine
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFromTo
parameter_list|(
name|int
name|fromPage
parameter_list|,
name|int
name|toPage
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|fromPage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|toPage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPrintRange
parameter_list|(
name|PrintRange
name|range
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|PrintRange
name|printRange
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setMargins
parameter_list|(
specifier|const
name|Margins
modifier|&
name|m
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setPageMargins
parameter_list|(
name|qreal
name|left
parameter_list|,
name|qreal
name|top
parameter_list|,
name|qreal
name|right
parameter_list|,
name|qreal
name|bottom
parameter_list|,
name|Unit
name|unit
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|getPageMargins
argument_list|(
name|qreal
operator|*
name|left
argument_list|,
name|qreal
operator|*
name|top
argument_list|,
name|qreal
operator|*
name|right
argument_list|,
name|qreal
operator|*
name|bottom
argument_list|,
name|Unit
name|unit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|int
name|metric
argument_list|(
name|PaintDeviceMetric
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setEngines
parameter_list|(
name|QPrintEngine
modifier|*
name|printEngine
parameter_list|,
name|QPaintEngine
modifier|*
name|paintEngine
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QPrinter
argument_list|)
end_macro
begin_expr_stmt
name|QScopedPointer
operator|<
name|QPrinterPrivate
operator|>
name|d_ptr
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|friend
name|class
name|QPrintDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QAbstractPrintDialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QAbstractPrintDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QPrintPreviewWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QTextDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QPageSetupWidget
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
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
comment|// QPRINTER_H
end_comment
end_unit
