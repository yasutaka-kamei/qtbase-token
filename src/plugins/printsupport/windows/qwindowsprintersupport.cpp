begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsprintersupport.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/QPrinterInfo>
end_include
begin_include
include|#
directive|include
file|<qprintengine_win_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_alpha_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qprinterinfo_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWindowsPrinterSupport
name|QWindowsPrinterSupport
operator|::
name|QWindowsPrinterSupport
parameter_list|()
member_init_list|:
name|QPlatformPrinterSupport
argument_list|()
block|{
name|DWORD
name|needed
init|=
literal|0
decl_stmt|;
name|DWORD
name|returned
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|EnumPrinters
argument_list|(
name|PRINTER_ENUM_LOCAL
operator||
name|PRINTER_ENUM_CONNECTIONS
argument_list|,
name|NULL
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|needed
argument_list|,
operator|&
name|returned
argument_list|)
condition|)
block|{
name|LPBYTE
name|buffer
init|=
operator|new
name|BYTE
index|[
name|needed
index|]
decl_stmt|;
if|if
condition|(
name|EnumPrinters
argument_list|(
name|PRINTER_ENUM_LOCAL
operator||
name|PRINTER_ENUM_CONNECTIONS
argument_list|,
name|NULL
argument_list|,
literal|4
argument_list|,
name|buffer
argument_list|,
name|needed
argument_list|,
operator|&
name|needed
argument_list|,
operator|&
name|returned
argument_list|)
condition|)
block|{
name|PPRINTER_INFO_4
name|infoList
init|=
cast|reinterpret_cast
argument_list|<
name|PPRINTER_INFO_4
argument_list|>
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|QString
name|defaultPrinterName
decl_stmt|;
name|QString
name|program
decl_stmt|;
name|QString
name|port
decl_stmt|;
name|QWin32PrintEngine
operator|::
name|queryDefaultPrinter
argument_list|(
name|defaultPrinterName
argument_list|,
name|program
argument_list|,
name|port
argument_list|)
expr_stmt|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
name|returned
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|printerName
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|infoList
index|[
name|i
index|]
operator|.
name|pPrinterName
argument_list|)
argument_list|)
decl_stmt|;
name|bool
name|isDefault
init|=
operator|(
name|printerName
operator|==
name|defaultPrinterName
operator|)
decl_stmt|;
name|QPrinterInfo
name|printerInfo
init|=
name|createPrinterInfo
argument_list|(
name|printerName
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|isDefault
argument_list|,
name|i
argument_list|)
decl_stmt|;
name|m_printers
operator|.
name|append
argument_list|(
name|printerInfo
argument_list|)
expr_stmt|;
block|}
block|}
operator|delete
index|[]
name|buffer
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsPrinterSupport
name|QWindowsPrinterSupport
operator|::
name|~
name|QWindowsPrinterSupport
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|createNativePrintEngine
name|QPrintEngine
modifier|*
name|QWindowsPrinterSupport
operator|::
name|createNativePrintEngine
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
parameter_list|)
block|{
return|return
operator|new
name|QWin32PrintEngine
argument_list|(
name|printerMode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPaintEngine
name|QPaintEngine
modifier|*
name|QWindowsPrinterSupport
operator|::
name|createPaintEngine
parameter_list|(
name|QPrintEngine
modifier|*
name|engine
parameter_list|,
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|printerMode
argument_list|)
return|return
cast|static_cast
argument_list|<
name|QWin32PrintEngine
operator|*
argument_list|>
argument_list|(
name|engine
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportedPaperSizes
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|QWindowsPrinterSupport
operator|::
name|supportedPaperSizes
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
name|printerInfo
parameter_list|)
specifier|const
block|{
return|return
name|QWin32PrintEngine
operator|::
name|supportedPaperSizes
argument_list|(
name|printerInfo
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
