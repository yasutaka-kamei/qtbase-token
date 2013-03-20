begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcupsprintengine_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|<qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qbuffer.h>
end_include
begin_include
include|#
directive|include
file|"private/qcups_p.h"
end_include
begin_include
include|#
directive|include
file|"qprinterinfo.h"
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// overrides QT_OPEN
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QCupsPrintEngine
name|QCupsPrintEngine
operator|::
name|QCupsPrintEngine
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
name|m
parameter_list|)
member_init_list|:
name|QPdfPrintEngine
argument_list|(
operator|*
operator|new
name|QCupsPrintEnginePrivate
argument_list|(
name|m
argument_list|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|QCupsPrintEngine
argument_list|)
expr_stmt|;
if|if
condition|(
name|QCUPSSupport
operator|::
name|isAvailable
argument_list|()
condition|)
block|{
name|QCUPSSupport
name|cups
decl_stmt|;
specifier|const
name|cups_dest_t
modifier|*
name|printers
init|=
name|cups
operator|.
name|availablePrinters
argument_list|()
decl_stmt|;
name|int
name|prnCount
init|=
name|cups
operator|.
name|availablePrintersCount
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|prnCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|printers
index|[
name|i
index|]
operator|.
name|is_default
condition|)
block|{
name|d
operator|->
name|printerName
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|printers
index|[
name|i
index|]
operator|.
name|name
argument_list|)
expr_stmt|;
name|d
operator|->
name|setCupsDefaults
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
name|state
operator|=
name|QPrinter
operator|::
name|Idle
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QCupsPrintEngine
name|QCupsPrintEngine
operator|::
name|~
name|QCupsPrintEngine
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|setProperty
name|void
name|QCupsPrintEngine
operator|::
name|setProperty
parameter_list|(
name|PrintEnginePropertyKey
name|key
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QCupsPrintEngine
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|int
argument_list|(
name|key
argument_list|)
condition|)
block|{
case|case
name|PPK_PaperSize
case|:
name|d
operator|->
name|printerPaperSize
operator|=
name|QPrinter
operator|::
name|PaperSize
argument_list|(
name|value
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setPaperSize
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_CupsPageRect
case|:
name|d
operator|->
name|cupsPageRect
operator|=
name|value
operator|.
name|toRect
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_CupsPaperRect
case|:
name|d
operator|->
name|cupsPaperRect
operator|=
name|value
operator|.
name|toRect
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_CupsOptions
case|:
name|d
operator|->
name|cupsOptions
operator|=
name|value
operator|.
name|toStringList
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_CupsStringPageSize
case|:
case|case
name|PPK_PaperName
case|:
name|d
operator|->
name|cupsStringPageSize
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
name|d
operator|->
name|setPaperName
argument_list|()
expr_stmt|;
break|break;
case|case
name|PPK_PrinterName
case|:
comment|// prevent setting the defaults again for the same printer
if|if
condition|(
name|d
operator|->
name|printerName
operator|!=
name|value
operator|.
name|toString
argument_list|()
condition|)
block|{
name|d
operator|->
name|printerName
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
name|d
operator|->
name|setCupsDefaults
argument_list|()
expr_stmt|;
block|}
break|break;
default|default:
name|QPdfPrintEngine
operator|::
name|setProperty
argument_list|(
name|key
argument_list|,
name|value
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_function
DECL|function|property
name|QVariant
name|QCupsPrintEngine
operator|::
name|property
parameter_list|(
name|PrintEnginePropertyKey
name|key
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QCupsPrintEngine
argument_list|)
expr_stmt|;
name|QVariant
name|ret
decl_stmt|;
switch|switch
condition|(
name|int
argument_list|(
name|key
argument_list|)
condition|)
block|{
case|case
name|PPK_SupportsMultipleCopies
case|:
name|ret
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|PPK_NumberOfCopies
case|:
name|ret
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|PPK_CupsPageRect
case|:
name|ret
operator|=
name|d
operator|->
name|cupsPageRect
expr_stmt|;
break|break;
case|case
name|PPK_CupsPaperRect
case|:
name|ret
operator|=
name|d
operator|->
name|cupsPaperRect
expr_stmt|;
break|break;
case|case
name|PPK_CupsOptions
case|:
name|ret
operator|=
name|d
operator|->
name|cupsOptions
expr_stmt|;
break|break;
case|case
name|PPK_CupsStringPageSize
case|:
case|case
name|PPK_PaperName
case|:
name|ret
operator|=
name|d
operator|->
name|cupsStringPageSize
expr_stmt|;
break|break;
default|default:
name|ret
operator|=
name|QPdfPrintEngine
operator|::
name|property
argument_list|(
name|key
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_constructor
DECL|function|QCupsPrintEnginePrivate
name|QCupsPrintEnginePrivate
operator|::
name|QCupsPrintEnginePrivate
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
name|m
parameter_list|)
member_init_list|:
name|QPdfPrintEnginePrivate
argument_list|(
name|m
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QCupsPrintEnginePrivate
name|QCupsPrintEnginePrivate
operator|::
name|~
name|QCupsPrintEnginePrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|openPrintDevice
name|bool
name|QCupsPrintEnginePrivate
operator|::
name|openPrintDevice
parameter_list|()
block|{
if|if
condition|(
name|outDevice
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|outputFileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
modifier|*
name|file
init|=
operator|new
name|QFile
argument_list|(
name|outputFileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|->
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Truncate
argument_list|)
condition|)
block|{
operator|delete
name|file
expr_stmt|;
return|return
literal|false
return|;
block|}
name|outDevice
operator|=
name|file
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|QCUPSSupport
operator|::
name|isAvailable
argument_list|()
condition|)
block|{
name|QCUPSSupport
name|cups
decl_stmt|;
name|QPair
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|ret
init|=
name|cups
operator|.
name|tempFd
argument_list|()
decl_stmt|;
if|if
condition|(
name|ret
operator|.
name|first
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QPdfPrinter: Could not open temporary file to print"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|cupsTempFile
operator|=
name|ret
operator|.
name|second
expr_stmt|;
name|outDevice
operator|=
operator|new
name|QFile
argument_list|()
expr_stmt|;
cast|static_cast
argument_list|<
name|QFile
operator|*
argument_list|>
argument_list|(
name|outDevice
argument_list|)
operator|->
name|open
argument_list|(
name|ret
operator|.
name|first
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|fd
operator|=
name|ret
operator|.
name|first
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|closePrintDevice
name|void
name|QCupsPrintEnginePrivate
operator|::
name|closePrintDevice
parameter_list|()
block|{
name|QPdfPrintEnginePrivate
operator|::
name|closePrintDevice
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|cupsTempFile
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|tempFile
init|=
name|cupsTempFile
decl_stmt|;
name|cupsTempFile
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCUPSSupport
name|cups
decl_stmt|;
comment|// Set up print options.
name|QByteArray
name|prnName
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
name|options
decl_stmt|;
name|QVector
argument_list|<
name|cups_option_t
argument_list|>
name|cupsOptStruct
decl_stmt|;
if|if
condition|(
operator|!
name|printerName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|prnName
operator|=
name|printerName
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QPrinterInfo
name|def
init|=
name|QPrinterInfo
operator|::
name|defaultPrinter
argument_list|()
decl_stmt|;
if|if
condition|(
name|def
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not determine printer to print to"
argument_list|)
expr_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|tempFile
argument_list|)
expr_stmt|;
return|return;
block|}
name|prnName
operator|=
name|def
operator|.
name|printerName
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|cupsStringPageSize
operator|.
name|isEmpty
argument_list|()
condition|)
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"media"
argument_list|,
name|cupsStringPageSize
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|copies
operator|>
literal|1
condition|)
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"copies"
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|copies
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|collate
condition|)
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"Collate"
argument_list|,
literal|"True"
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|duplex
condition|)
block|{
case|case
name|QPrinter
operator|::
name|DuplexNone
case|:
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"sides"
argument_list|,
literal|"one-sided"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPrinter
operator|::
name|DuplexAuto
case|:
if|if
condition|(
operator|!
name|landscape
condition|)
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"sides"
argument_list|,
literal|"two-sided-long-edge"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"sides"
argument_list|,
literal|"two-sided-short-edge"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPrinter
operator|::
name|DuplexLongSide
case|:
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"sides"
argument_list|,
literal|"two-sided-long-edge"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPrinter
operator|::
name|DuplexShortSide
case|:
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"sides"
argument_list|,
literal|"two-sided-short-edge"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|QCUPSSupport
operator|::
name|cupsVersion
argument_list|()
operator|>=
literal|10300
operator|&&
name|landscape
condition|)
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"landscape"
argument_list|,
literal|""
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
operator|::
name|const_iterator
name|it
init|=
name|cupsOptions
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|cupsOptions
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|options
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
operator|(
operator|*
name|it
operator|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|,
operator|(
operator|*
operator|(
name|it
operator|+
literal|1
operator|)
operator|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|it
operator|+=
literal|2
expr_stmt|;
block|}
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|options
operator|.
name|size
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
name|cups_option_t
name|opt
decl_stmt|;
name|opt
operator|.
name|name
operator|=
name|options
index|[
name|c
index|]
operator|.
name|first
operator|.
name|data
argument_list|()
expr_stmt|;
name|opt
operator|.
name|value
operator|=
name|options
index|[
name|c
index|]
operator|.
name|second
operator|.
name|data
argument_list|()
expr_stmt|;
name|cupsOptStruct
operator|.
name|append
argument_list|(
name|opt
argument_list|)
expr_stmt|;
block|}
comment|// Print the file.
name|cups_option_t
modifier|*
name|optPtr
init|=
name|cupsOptStruct
operator|.
name|size
argument_list|()
condition|?
operator|&
name|cupsOptStruct
operator|.
name|first
argument_list|()
else|:
literal|0
decl_stmt|;
name|cups
operator|.
name|printFile
argument_list|(
name|prnName
operator|.
name|constData
argument_list|()
argument_list|,
name|tempFile
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|title
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|cupsOptStruct
operator|.
name|size
argument_list|()
argument_list|,
name|optPtr
argument_list|)
expr_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|tempFile
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|updatePaperSize
name|void
name|QCupsPrintEnginePrivate
operator|::
name|updatePaperSize
parameter_list|()
block|{
if|if
condition|(
name|printerPaperSize
operator|==
name|QPrinter
operator|::
name|Custom
condition|)
block|{
name|paperSize
operator|=
name|customPaperSize
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|cupsPaperRect
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QRect
name|r
init|=
name|cupsPaperRect
decl_stmt|;
name|paperSize
operator|=
name|r
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QPdf
operator|::
name|PaperSize
name|s
init|=
name|QPdf
operator|::
name|paperSize
argument_list|(
name|printerPaperSize
argument_list|)
decl_stmt|;
name|paperSize
operator|=
name|QSize
argument_list|(
name|s
operator|.
name|width
argument_list|,
name|s
operator|.
name|height
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setPaperSize
name|void
name|QCupsPrintEnginePrivate
operator|::
name|setPaperSize
parameter_list|()
block|{
if|if
condition|(
name|QCUPSSupport
operator|::
name|isAvailable
argument_list|()
condition|)
block|{
name|QCUPSSupport
name|cups
decl_stmt|;
name|QPdf
operator|::
name|PaperSize
name|size
init|=
name|QPdf
operator|::
name|paperSize
argument_list|(
name|QPrinter
operator|::
name|PaperSize
argument_list|(
name|printerPaperSize
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|cups
operator|.
name|currentPPD
argument_list|()
condition|)
block|{
name|cupsStringPageSize
operator|=
name|QLatin1String
argument_list|(
literal|"Custom"
argument_list|)
expr_stmt|;
specifier|const
name|ppd_option_t
modifier|*
name|pageSizes
init|=
name|cups
operator|.
name|pageSizes
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pageSizes
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
block|{
name|QByteArray
name|cupsPageSize
init|=
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|choice
decl_stmt|;
name|QRect
name|tmpCupsPaperRect
init|=
name|cups
operator|.
name|paperRect
argument_list|(
name|cupsPageSize
argument_list|)
decl_stmt|;
name|QRect
name|tmpCupsPageRect
init|=
name|cups
operator|.
name|pageRect
argument_list|(
name|cupsPageSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|qAbs
argument_list|(
name|size
operator|.
name|width
operator|-
name|tmpCupsPaperRect
operator|.
name|width
argument_list|()
argument_list|)
operator|<
literal|5
operator|&&
name|qAbs
argument_list|(
name|size
operator|.
name|height
operator|-
name|tmpCupsPaperRect
operator|.
name|height
argument_list|()
argument_list|)
operator|<
literal|5
condition|)
block|{
name|cupsPaperRect
operator|=
name|tmpCupsPaperRect
expr_stmt|;
name|cupsPageRect
operator|=
name|tmpCupsPageRect
expr_stmt|;
name|cupsStringPageSize
operator|=
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|text
expr_stmt|;
name|leftMargin
operator|=
name|cupsPageRect
operator|.
name|x
argument_list|()
operator|-
name|cupsPaperRect
operator|.
name|x
argument_list|()
expr_stmt|;
name|topMargin
operator|=
name|cupsPageRect
operator|.
name|y
argument_list|()
operator|-
name|cupsPaperRect
operator|.
name|y
argument_list|()
expr_stmt|;
name|rightMargin
operator|=
name|cupsPaperRect
operator|.
name|right
argument_list|()
operator|-
name|cupsPageRect
operator|.
name|right
argument_list|()
expr_stmt|;
name|bottomMargin
operator|=
name|cupsPaperRect
operator|.
name|bottom
argument_list|()
operator|-
name|cupsPageRect
operator|.
name|bottom
argument_list|()
expr_stmt|;
name|updatePaperSize
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|setPaperName
name|void
name|QCupsPrintEnginePrivate
operator|::
name|setPaperName
parameter_list|()
block|{
if|if
condition|(
name|QCUPSSupport
operator|::
name|isAvailable
argument_list|()
condition|)
block|{
name|QCUPSSupport
name|cups
decl_stmt|;
if|if
condition|(
name|cups
operator|.
name|currentPPD
argument_list|()
condition|)
block|{
specifier|const
name|ppd_option_t
modifier|*
name|pageSizes
init|=
name|cups
operator|.
name|pageSizes
argument_list|()
decl_stmt|;
name|bool
name|foundPaperName
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pageSizes
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|cupsStringPageSize
operator|==
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|text
condition|)
block|{
name|foundPaperName
operator|=
literal|true
expr_stmt|;
name|QByteArray
name|cupsPageSize
init|=
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|choice
decl_stmt|;
name|cupsPaperRect
operator|=
name|cups
operator|.
name|paperRect
argument_list|(
name|cupsPageSize
argument_list|)
expr_stmt|;
name|cupsPageRect
operator|=
name|cups
operator|.
name|pageRect
argument_list|(
name|cupsPageSize
argument_list|)
expr_stmt|;
name|leftMargin
operator|=
name|cupsPageRect
operator|.
name|x
argument_list|()
operator|-
name|cupsPaperRect
operator|.
name|x
argument_list|()
expr_stmt|;
name|topMargin
operator|=
name|cupsPageRect
operator|.
name|y
argument_list|()
operator|-
name|cupsPaperRect
operator|.
name|y
argument_list|()
expr_stmt|;
name|rightMargin
operator|=
name|cupsPaperRect
operator|.
name|right
argument_list|()
operator|-
name|cupsPageRect
operator|.
name|right
argument_list|()
expr_stmt|;
name|bottomMargin
operator|=
name|cupsPaperRect
operator|.
name|bottom
argument_list|()
operator|-
name|cupsPageRect
operator|.
name|bottom
argument_list|()
expr_stmt|;
name|printerPaperSize
operator|=
name|QPrinter
operator|::
name|Custom
expr_stmt|;
name|customPaperSize
operator|=
name|cupsPaperRect
operator|.
name|size
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|ps
init|=
literal|0
init|;
name|ps
operator|<
name|QPrinter
operator|::
name|NPageSize
condition|;
operator|++
name|ps
control|)
block|{
name|QPdf
operator|::
name|PaperSize
name|size
init|=
name|QPdf
operator|::
name|paperSize
argument_list|(
name|QPrinter
operator|::
name|PaperSize
argument_list|(
name|ps
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|qAbs
argument_list|(
name|size
operator|.
name|width
operator|-
name|cupsPaperRect
operator|.
name|width
argument_list|()
argument_list|)
operator|<
literal|5
operator|&&
name|qAbs
argument_list|(
name|size
operator|.
name|height
operator|-
name|cupsPaperRect
operator|.
name|height
argument_list|()
argument_list|)
operator|<
literal|5
condition|)
block|{
name|printerPaperSize
operator|=
cast|static_cast
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
argument_list|(
name|ps
argument_list|)
expr_stmt|;
name|customPaperSize
operator|=
name|QSize
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
name|updatePaperSize
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|foundPaperName
condition|)
name|cupsStringPageSize
operator|=
name|QString
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|setCupsDefaults
name|void
name|QCupsPrintEnginePrivate
operator|::
name|setCupsDefaults
parameter_list|()
block|{
if|if
condition|(
name|QCUPSSupport
operator|::
name|isAvailable
argument_list|()
condition|)
block|{
name|int
name|cupsPrinterIndex
init|=
operator|-
literal|1
decl_stmt|;
name|QCUPSSupport
name|cups
decl_stmt|;
specifier|const
name|cups_dest_t
modifier|*
name|printers
init|=
name|cups
operator|.
name|availablePrinters
argument_list|()
decl_stmt|;
name|int
name|prnCount
init|=
name|cups
operator|.
name|availablePrintersCount
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|prnCount
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|name
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|printers
index|[
name|i
index|]
operator|.
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|==
name|printerName
condition|)
block|{
name|cupsPrinterIndex
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|cupsPrinterIndex
operator|<
literal|0
condition|)
return|return;
name|cups
operator|.
name|setCurrentPrinter
argument_list|(
name|cupsPrinterIndex
argument_list|)
expr_stmt|;
if|if
condition|(
name|cups
operator|.
name|currentPPD
argument_list|()
condition|)
block|{
specifier|const
name|ppd_option_t
modifier|*
name|ppdDuplex
init|=
name|cups
operator|.
name|ppdOption
argument_list|(
literal|"Duplex"
argument_list|)
decl_stmt|;
if|if
condition|(
name|ppdDuplex
condition|)
block|{
if|if
condition|(
name|qstrcmp
argument_list|(
name|ppdDuplex
operator|->
name|defchoice
argument_list|,
literal|"DuplexTumble"
argument_list|)
operator|==
literal|0
condition|)
name|duplex
operator|=
name|QPrinter
operator|::
name|DuplexShortSide
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|ppdDuplex
operator|->
name|defchoice
argument_list|,
literal|"DuplexNoTumble"
argument_list|)
operator|==
literal|0
condition|)
name|duplex
operator|=
name|QPrinter
operator|::
name|DuplexLongSide
expr_stmt|;
else|else
name|duplex
operator|=
name|QPrinter
operator|::
name|DuplexNone
expr_stmt|;
block|}
name|grayscale
operator|=
operator|!
name|cups
operator|.
name|currentPPD
argument_list|()
operator|->
name|color_device
expr_stmt|;
specifier|const
name|ppd_option_t
modifier|*
name|ppdCollate
init|=
name|cups
operator|.
name|ppdOption
argument_list|(
literal|"Collate"
argument_list|)
decl_stmt|;
if|if
condition|(
name|ppdCollate
condition|)
name|collate
operator|=
name|qstrcmp
argument_list|(
name|ppdCollate
operator|->
name|defchoice
argument_list|,
literal|"True"
argument_list|)
operator|==
literal|0
expr_stmt|;
specifier|const
name|ppd_option_t
modifier|*
name|pageSizes
init|=
name|cups
operator|.
name|pageSizes
argument_list|()
decl_stmt|;
name|QByteArray
name|cupsPageSize
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pageSizes
operator|->
name|num_choices
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|marked
argument_list|)
operator|==
literal|1
condition|)
block|{
name|cupsPageSize
operator|=
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|choice
expr_stmt|;
name|cupsStringPageSize
operator|=
name|pageSizes
operator|->
name|choices
index|[
name|i
index|]
operator|.
name|text
expr_stmt|;
block|}
block|}
name|cupsOptions
operator|=
name|cups
operator|.
name|options
argument_list|()
expr_stmt|;
name|cupsPaperRect
operator|=
name|cups
operator|.
name|paperRect
argument_list|(
name|cupsPageSize
argument_list|)
expr_stmt|;
name|cupsPageRect
operator|=
name|cups
operator|.
name|pageRect
argument_list|(
name|cupsPageSize
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|ps
init|=
literal|0
init|;
name|ps
operator|<
name|QPrinter
operator|::
name|NPageSize
condition|;
operator|++
name|ps
control|)
block|{
name|QPdf
operator|::
name|PaperSize
name|size
init|=
name|QPdf
operator|::
name|paperSize
argument_list|(
name|QPrinter
operator|::
name|PaperSize
argument_list|(
name|ps
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|qAbs
argument_list|(
name|size
operator|.
name|width
operator|-
name|cupsPaperRect
operator|.
name|width
argument_list|()
argument_list|)
operator|<
literal|5
operator|&&
name|qAbs
argument_list|(
name|size
operator|.
name|height
operator|-
name|cupsPaperRect
operator|.
name|height
argument_list|()
argument_list|)
operator|<
literal|5
condition|)
block|{
name|printerPaperSize
operator|=
cast|static_cast
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
argument_list|(
name|ps
argument_list|)
expr_stmt|;
name|leftMargin
operator|=
name|cupsPageRect
operator|.
name|x
argument_list|()
operator|-
name|cupsPaperRect
operator|.
name|x
argument_list|()
expr_stmt|;
name|topMargin
operator|=
name|cupsPageRect
operator|.
name|y
argument_list|()
operator|-
name|cupsPaperRect
operator|.
name|y
argument_list|()
expr_stmt|;
name|rightMargin
operator|=
name|cupsPaperRect
operator|.
name|right
argument_list|()
operator|-
name|cupsPageRect
operator|.
name|right
argument_list|()
expr_stmt|;
name|bottomMargin
operator|=
name|cupsPaperRect
operator|.
name|bottom
argument_list|()
operator|-
name|cupsPageRect
operator|.
name|bottom
argument_list|()
expr_stmt|;
name|updatePaperSize
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
end_unit
