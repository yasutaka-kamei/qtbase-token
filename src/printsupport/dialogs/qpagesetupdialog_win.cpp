begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpagesetupdialog.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
end_ifndef
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|"../kernel/qprintengine_win_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstractpagesetupdialog_p.h"
end_include
begin_include
include|#
directive|include
file|"qprinter.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QPageSetupDialogPrivate
class|class
name|QPageSetupDialogPrivate
super|:
specifier|public
name|QAbstractPageSetupDialogPrivate
block|{
block|}
class|;
end_class
begin_constructor
DECL|function|QPageSetupDialog
name|QPageSetupDialog
operator|::
name|QPageSetupDialog
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractPageSetupDialog
argument_list|(
operator|*
operator|(
operator|new
name|QPageSetupDialogPrivate
operator|)
argument_list|,
name|printer
argument_list|,
name|parent
argument_list|)
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DontShowOnScreen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QPageSetupDialog
name|QPageSetupDialog
operator|::
name|QPageSetupDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractPageSetupDialog
argument_list|(
operator|*
operator|(
operator|new
name|QPageSetupDialogPrivate
operator|)
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DontShowOnScreen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|exec
name|int
name|QPageSetupDialog
operator|::
name|exec
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPageSetupDialog
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|printer
operator|->
name|outputFormat
argument_list|()
operator|!=
name|QPrinter
operator|::
name|NativeFormat
condition|)
return|return
name|Rejected
return|;
name|QWin32PrintEngine
modifier|*
name|engine
init|=
cast|static_cast
argument_list|<
name|QWin32PrintEngine
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|printer
operator|->
name|paintEngine
argument_list|()
argument_list|)
decl_stmt|;
name|QWin32PrintEnginePrivate
modifier|*
name|ep
init|=
cast|static_cast
argument_list|<
name|QWin32PrintEnginePrivate
operator|*
argument_list|>
argument_list|(
name|engine
operator|->
name|d_ptr
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|PAGESETUPDLG
name|psd
decl_stmt|;
name|memset
argument_list|(
operator|&
name|psd
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|PAGESETUPDLG
argument_list|)
argument_list|)
expr_stmt|;
name|psd
operator|.
name|lStructSize
operator|=
sizeof|sizeof
argument_list|(
name|PAGESETUPDLG
argument_list|)
expr_stmt|;
comment|// we need a temp DEVMODE struct if we don't have a global DEVMODE
name|HGLOBAL
name|hDevMode
init|=
literal|0
decl_stmt|;
name|int
name|devModeSize
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|ep
operator|->
name|globalDevMode
condition|)
block|{
name|devModeSize
operator|=
sizeof|sizeof
argument_list|(
name|DEVMODE
argument_list|)
operator|+
name|ep
operator|->
name|devMode
operator|->
name|dmDriverExtra
expr_stmt|;
name|hDevMode
operator|=
name|GlobalAlloc
argument_list|(
name|GHND
argument_list|,
name|devModeSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|hDevMode
condition|)
block|{
name|void
modifier|*
name|dest
init|=
name|GlobalLock
argument_list|(
name|hDevMode
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|dest
argument_list|,
name|ep
operator|->
name|devMode
argument_list|,
name|devModeSize
argument_list|)
expr_stmt|;
name|GlobalUnlock
argument_list|(
name|hDevMode
argument_list|)
expr_stmt|;
block|}
name|psd
operator|.
name|hDevMode
operator|=
name|hDevMode
expr_stmt|;
block|}
else|else
block|{
name|psd
operator|.
name|hDevMode
operator|=
name|ep
operator|->
name|devMode
expr_stmt|;
block|}
name|HGLOBAL
modifier|*
name|tempDevNames
init|=
name|ep
operator|->
name|createDevNames
argument_list|()
decl_stmt|;
name|psd
operator|.
name|hDevNames
operator|=
name|tempDevNames
expr_stmt|;
name|QWidget
modifier|*
name|parent
init|=
name|parentWidget
argument_list|()
decl_stmt|;
name|parent
operator|=
name|parent
condition|?
name|parent
operator|->
name|window
argument_list|()
else|:
name|QApplication
operator|::
name|activeWindow
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|parent
operator|||
name|parent
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Created
argument_list|)
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|parentWindow
init|=
name|parent
operator|->
name|windowHandle
argument_list|()
decl_stmt|;
name|psd
operator|.
name|hwndOwner
operator|=
name|parentWindow
condition|?
operator|(
name|HWND
operator|)
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
operator|->
name|nativeResourceForWindow
argument_list|(
literal|"handle"
argument_list|,
name|parentWindow
argument_list|)
else|:
literal|0
expr_stmt|;
name|psd
operator|.
name|Flags
operator|=
name|PSD_MARGINS
expr_stmt|;
name|double
name|multiplier
init|=
literal|1
decl_stmt|;
switch|switch
condition|(
name|QLocale
operator|::
name|system
argument_list|()
operator|.
name|measurementSystem
argument_list|()
condition|)
block|{
case|case
name|QLocale
operator|::
name|MetricSystem
case|:
name|psd
operator|.
name|Flags
operator||=
name|PSD_INHUNDREDTHSOFMILLIMETERS
expr_stmt|;
name|multiplier
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|QLocale
operator|::
name|ImperialSystem
case|:
case|case
name|QLocale
operator|::
name|ImperialUKSystem
case|:
name|psd
operator|.
name|Flags
operator||=
name|PSD_INTHOUSANDTHSOFINCHES
expr_stmt|;
name|multiplier
operator|=
literal|25.4
operator|/
literal|10
expr_stmt|;
break|break;
block|}
name|QRect
name|marginRect
init|=
name|ep
operator|->
name|getPageMargins
argument_list|()
decl_stmt|;
name|psd
operator|.
name|rtMargin
operator|.
name|left
operator|=
name|marginRect
operator|.
name|left
argument_list|()
operator|/
name|multiplier
expr_stmt|;
name|psd
operator|.
name|rtMargin
operator|.
name|top
operator|=
name|marginRect
operator|.
name|top
argument_list|()
operator|/
name|multiplier
expr_stmt|;
name|psd
operator|.
name|rtMargin
operator|.
name|right
operator|=
name|marginRect
operator|.
name|width
argument_list|()
operator|/
name|multiplier
expr_stmt|;
empty_stmt|;
name|psd
operator|.
name|rtMargin
operator|.
name|bottom
operator|=
name|marginRect
operator|.
name|height
argument_list|()
operator|/
name|multiplier
expr_stmt|;
empty_stmt|;
name|QDialog
operator|::
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|bool
name|result
init|=
name|PageSetupDlg
argument_list|(
operator|&
name|psd
argument_list|)
decl_stmt|;
name|QDialog
operator|::
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
condition|)
block|{
name|ep
operator|->
name|readDevnames
argument_list|(
name|psd
operator|.
name|hDevNames
argument_list|)
expr_stmt|;
name|ep
operator|->
name|readDevmode
argument_list|(
name|psd
operator|.
name|hDevMode
argument_list|)
expr_stmt|;
name|QRect
name|theseMargins
init|=
name|QRect
argument_list|(
name|psd
operator|.
name|rtMargin
operator|.
name|left
operator|*
name|multiplier
argument_list|,
name|psd
operator|.
name|rtMargin
operator|.
name|top
operator|*
name|multiplier
argument_list|,
name|psd
operator|.
name|rtMargin
operator|.
name|right
operator|*
name|multiplier
argument_list|,
name|psd
operator|.
name|rtMargin
operator|.
name|bottom
operator|*
name|multiplier
argument_list|)
decl_stmt|;
if|if
condition|(
name|theseMargins
operator|!=
name|marginRect
condition|)
block|{
name|ep
operator|->
name|setPageMargins
argument_list|(
name|psd
operator|.
name|rtMargin
operator|.
name|left
operator|*
name|multiplier
argument_list|,
name|psd
operator|.
name|rtMargin
operator|.
name|top
operator|*
name|multiplier
argument_list|,
name|psd
operator|.
name|rtMargin
operator|.
name|right
operator|*
name|multiplier
argument_list|,
name|psd
operator|.
name|rtMargin
operator|.
name|bottom
operator|*
name|multiplier
argument_list|)
expr_stmt|;
block|}
name|ep
operator|->
name|updateCustomPaperSize
argument_list|()
expr_stmt|;
comment|// copy from our temp DEVMODE struct
if|if
condition|(
operator|!
name|ep
operator|->
name|globalDevMode
operator|&&
name|hDevMode
condition|)
block|{
name|void
modifier|*
name|src
init|=
name|GlobalLock
argument_list|(
name|hDevMode
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|ep
operator|->
name|devMode
argument_list|,
name|src
argument_list|,
name|devModeSize
argument_list|)
expr_stmt|;
name|GlobalUnlock
argument_list|(
name|hDevMode
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|ep
operator|->
name|globalDevMode
operator|&&
name|hDevMode
condition|)
name|GlobalFree
argument_list|(
name|hDevMode
argument_list|)
expr_stmt|;
name|GlobalFree
argument_list|(
name|tempDevNames
argument_list|)
expr_stmt|;
name|done
argument_list|(
name|result
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QPageSetupDialog
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
if|if
condition|(
operator|!
name|visible
condition|)
return|return;
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
