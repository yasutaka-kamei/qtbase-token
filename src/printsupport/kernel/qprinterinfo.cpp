begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:FDL$ ** GNU Free Documentation License ** Alternatively, this file may be used under the terms of the GNU Free ** Documentation License version 1.3 as published by the Free Software ** Foundation and appearing in the file included in the packaging of ** this file. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms ** and conditions contained in a signed written agreement between you ** and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qprinterinfo.h"
end_include
begin_include
include|#
directive|include
file|"qprinterinfo_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|<qpa/qplatformprintplugin.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformprintersupport.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|shared_null
name|QPrinterInfoPrivate
name|QPrinterInfoPrivate
operator|::
name|shared_null
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \class QPrinterInfo      \brief The QPrinterInfo class gives access to information about     existing printers.      \ingroup printing     \inmodule QtPrintSupport      Use the static functions to generate a list of QPrinterInfo     objects. Each QPrinterInfo object in the list represents a single     printer and can be queried for name, supported paper sizes, and     whether or not it is the default printer.      \since 4.4 */
end_comment
begin_comment
comment|/*!     \fn QList<QPrinterInfo> QPrinterInfo::availablePrinters()      Returns a list of available printers on the system. */
end_comment
begin_comment
comment|/*!     \fn QPrinterInfo QPrinterInfo::defaultPrinter()      Returns the default printer on the system.      The return value should be checked using isNull() before being     used, in case there is no default printer.      On some systems it is possible for there to be available printers     but none of them set to be the default printer.      \sa isNull()     \sa isDefault()     \sa availablePrinters() */
end_comment
begin_comment
comment|/*!     Constructs an empty QPrinterInfo object.      \sa isNull() */
end_comment
begin_constructor
DECL|function|QPrinterInfo
name|QPrinterInfo
operator|::
name|QPrinterInfo
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|&
name|QPrinterInfoPrivate
operator|::
name|shared_null
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a copy of \a other. */
end_comment
begin_constructor
DECL|function|QPrinterInfo
name|QPrinterInfo
operator|::
name|QPrinterInfo
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPrinterInfoPrivate
argument_list|(
operator|*
name|other
operator|.
name|d_ptr
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QPrinterInfo object from \a printer. */
end_comment
begin_constructor
DECL|function|QPrinterInfo
name|QPrinterInfo
operator|::
name|QPrinterInfo
parameter_list|(
specifier|const
name|QPrinter
modifier|&
name|printer
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|&
name|QPrinterInfoPrivate
operator|::
name|shared_null
argument_list|)
block|{
name|QPlatformPrinterSupport
modifier|*
name|ps
init|=
name|QPlatformPrinterSupportPlugin
operator|::
name|get
argument_list|()
decl_stmt|;
if|if
condition|(
name|ps
condition|)
block|{
name|QPrinterInfo
name|pi
init|=
name|ps
operator|->
name|printerInfo
argument_list|(
name|printer
operator|.
name|printerName
argument_list|()
argument_list|)
decl_stmt|;
name|d_ptr
operator|.
name|reset
argument_list|(
operator|new
name|QPrinterInfoPrivate
argument_list|(
operator|*
name|pi
operator|.
name|d_ptr
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QPrinterInfo
name|QPrinterInfo
operator|::
name|QPrinterInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPrinterInfoPrivate
argument_list|(
name|name
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QPrinterInfo object. References to the values in the     object become invalid. */
end_comment
begin_destructor
DECL|function|~QPrinterInfo
name|QPrinterInfo
operator|::
name|~
name|QPrinterInfo
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Sets the QPrinterInfo object to be equal to \a other. */
end_comment
begin_function
DECL|function|operator =
name|QPrinterInfo
modifier|&
name|QPrinterInfo
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
name|other
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|d_ptr
argument_list|)
expr_stmt|;
name|d_ptr
operator|.
name|reset
argument_list|(
operator|new
name|QPrinterInfoPrivate
argument_list|(
operator|*
name|other
operator|.
name|d_ptr
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the printer.      This is a unique id to identify the printer and may not be human-readable.      \sa QPrinterInfo::description()     \sa QPrinter::setPrinterName() */
end_comment
begin_function
DECL|function|printerName
name|QString
name|QPrinterInfo
operator|::
name|printerName
parameter_list|()
specifier|const
block|{
specifier|const
name|Q_D
argument_list|(
name|QPrinterInfo
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the human-readable description of the printer.      \since 5.0     \sa QPrinterInfo::printerName() */
end_comment
begin_function
DECL|function|description
name|QString
name|QPrinterInfo
operator|::
name|description
parameter_list|()
specifier|const
block|{
specifier|const
name|Q_D
argument_list|(
name|QPrinterInfo
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|description
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the human-readable location of the printer.      \since 5.0 */
end_comment
begin_function
DECL|function|location
name|QString
name|QPrinterInfo
operator|::
name|location
parameter_list|()
specifier|const
block|{
specifier|const
name|Q_D
argument_list|(
name|QPrinterInfo
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|location
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the human-readable make and model of the printer.      \since 5.0 */
end_comment
begin_function
DECL|function|makeAndModel
name|QString
name|QPrinterInfo
operator|::
name|makeAndModel
parameter_list|()
specifier|const
block|{
specifier|const
name|Q_D
argument_list|(
name|QPrinterInfo
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|makeAndModel
return|;
block|}
end_function
begin_comment
comment|/*!     Returns whether this QPrinterInfo object holds a printer definition.      An empty QPrinterInfo object could result for example from calling     defaultPrinter() when there are no printers on the system. */
end_comment
begin_function
DECL|function|isNull
name|bool
name|QPrinterInfo
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPrinterInfo
argument_list|)
expr_stmt|;
return|return
name|d
operator|==
operator|&
name|QPrinterInfoPrivate
operator|::
name|shared_null
return|;
block|}
end_function
begin_comment
comment|/*!     Returns whether this printer is the default printer. */
end_comment
begin_function
DECL|function|isDefault
name|bool
name|QPrinterInfo
operator|::
name|isDefault
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPrinterInfo
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|isDefault
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of supported paper sizes by the printer.      Not all printer drivers support this query, so the list may be empty.     On Mac OS X 10.3, this function always returns an empty list.      \since 4.4 */
end_comment
begin_function
DECL|function|supportedPaperSizes
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|QPrinterInfo
operator|::
name|supportedPaperSizes
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPrinterInfo
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isNull
argument_list|()
operator|&&
operator|!
name|d
operator|->
name|hasPaperSizes
condition|)
block|{
name|d
operator|->
name|paperSizes
operator|=
name|QPlatformPrinterSupportPlugin
operator|::
name|get
argument_list|()
operator|->
name|supportedPaperSizes
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|hasPaperSizes
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|d
operator|->
name|paperSizes
return|;
block|}
end_function
begin_function
DECL|function|availablePrinters
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|QPrinterInfo
operator|::
name|availablePrinters
parameter_list|()
block|{
name|QPlatformPrinterSupport
modifier|*
name|ps
init|=
name|QPlatformPrinterSupportPlugin
operator|::
name|get
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ps
condition|)
return|return
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
argument_list|()
return|;
return|return
name|ps
operator|->
name|availablePrinters
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultPrinter
name|QPrinterInfo
name|QPrinterInfo
operator|::
name|defaultPrinter
parameter_list|()
block|{
name|QPlatformPrinterSupport
modifier|*
name|ps
init|=
name|QPlatformPrinterSupportPlugin
operator|::
name|get
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ps
condition|)
return|return
name|QPrinterInfo
argument_list|()
return|;
return|return
name|ps
operator|->
name|defaultPrinter
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the named printer.      The return value should be checked using isNull() before being     used, in case the named printer does not exist.      \since 5.0     \sa isNull() */
end_comment
begin_function
DECL|function|printerInfo
name|QPrinterInfo
name|QPrinterInfo
operator|::
name|printerInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|printerName
parameter_list|)
block|{
name|QPlatformPrinterSupport
modifier|*
name|ps
init|=
name|QPlatformPrinterSupportPlugin
operator|::
name|get
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ps
condition|)
return|return
name|QPrinterInfo
argument_list|()
return|;
return|return
name|ps
operator|->
name|printerInfo
argument_list|(
name|printerName
argument_list|)
return|;
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
