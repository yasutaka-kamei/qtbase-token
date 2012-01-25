begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSXPSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSXPSTYLE_P_H
define|#
directive|define
name|QWINDOWSXPSTYLE_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|"qwindowsxpstyle.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsstyle_p.h"
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_comment
comment|// Note, these tests are duplicated in qwizard_win.cpp.
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_GNU
end_ifdef
begin_include
include|#
directive|include
file|<w32api.h>
end_include
begin_if
if|#
directive|if
operator|(
name|__W32API_MAJOR_VERSION
operator|>=
literal|3
operator|||
operator|(
name|__W32API_MAJOR_VERSION
operator|==
literal|2
operator|&&
name|__W32API_MINOR_VERSION
operator|>=
literal|5
operator|)
operator|)
end_if
begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_WINNT
end_ifdef
begin_undef
DECL|macro|_WIN32_WINNT
undef|#
directive|undef
name|_WIN32_WINNT
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|_WIN32_WINNT
define|#
directive|define
name|_WIN32_WINNT
value|0x0501
end_define
begin_include
include|#
directive|include
file|<commctrl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<uxtheme.h>
end_include
begin_if
if|#
directive|if
name|WINVER
operator|>=
literal|0x0600
end_if
begin_include
include|#
directive|include
file|<vssym32.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<tmschema.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// Older Platform SDKs do not have the extended DrawThemeBackgroundEx
end_comment
begin_comment
comment|// function. We add the needed parts here, and use the extended
end_comment
begin_comment
comment|// function dynamically, if available in uxtheme.dll. Else, we revert
end_comment
begin_comment
comment|// back to using the DrawThemeBackground function.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DTBG_OMITBORDER
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|DTBG_CLIPRECT
end_ifndef
begin_define
DECL|macro|DTBG_CLIPRECT
define|#
directive|define
name|DTBG_CLIPRECT
value|0x00000001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|DTBG_DRAWSOLID
end_ifndef
begin_define
DECL|macro|DTBG_DRAWSOLID
define|#
directive|define
name|DTBG_DRAWSOLID
value|0x00000002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|DTBG_OMITBORDER
end_ifndef
begin_define
DECL|macro|DTBG_OMITBORDER
define|#
directive|define
name|DTBG_OMITBORDER
value|0x00000004
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|DTBG_OMITCONTENT
end_ifndef
begin_define
DECL|macro|DTBG_OMITCONTENT
define|#
directive|define
name|DTBG_OMITCONTENT
value|0x00000008
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|DTBG_COMPUTINGREGION
end_ifndef
begin_define
DECL|macro|DTBG_COMPUTINGREGION
define|#
directive|define
name|DTBG_COMPUTINGREGION
value|0x00000010
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|DTBG_MIRRORDC
end_ifndef
begin_define
DECL|macro|DTBG_MIRRORDC
define|#
directive|define
name|DTBG_MIRRORDC
value|0x00000020
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|struct|_DTBGOPTS
typedef|typedef
struct|struct
name|_DTBGOPTS
block|{
DECL|member|dwSize
name|DWORD
name|dwSize
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
DECL|member|rcClip
name|RECT
name|rcClip
decl_stmt|;
block|}
DECL|typedef|DTBGOPTS
DECL|typedef|PDTBGOPTS
name|DTBGOPTS
operator|,
typedef|*
name|PDTBGOPTS
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _DTBGOPTS
end_comment
begin_comment
comment|// Undefined for some compile environments
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_TEXTCOLOR
end_ifndef
begin_define
DECL|macro|TMT_TEXTCOLOR
define|#
directive|define
name|TMT_TEXTCOLOR
value|3803
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_BORDERCOLORHINT
end_ifndef
begin_define
DECL|macro|TMT_BORDERCOLORHINT
define|#
directive|define
name|TMT_BORDERCOLORHINT
value|3822
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_BORDERSIZE
end_ifndef
begin_define
DECL|macro|TMT_BORDERSIZE
define|#
directive|define
name|TMT_BORDERSIZE
value|2403
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_BORDERONLY
end_ifndef
begin_define
DECL|macro|TMT_BORDERONLY
define|#
directive|define
name|TMT_BORDERONLY
value|2203
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_TRANSPARENTCOLOR
end_ifndef
begin_define
DECL|macro|TMT_TRANSPARENTCOLOR
define|#
directive|define
name|TMT_TRANSPARENTCOLOR
value|3809
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_CAPTIONMARGINS
end_ifndef
begin_define
DECL|macro|TMT_CAPTIONMARGINS
define|#
directive|define
name|TMT_CAPTIONMARGINS
value|3603
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_CONTENTMARGINS
end_ifndef
begin_define
DECL|macro|TMT_CONTENTMARGINS
define|#
directive|define
name|TMT_CONTENTMARGINS
value|3602
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_SIZINGMARGINS
end_ifndef
begin_define
DECL|macro|TMT_SIZINGMARGINS
define|#
directive|define
name|TMT_SIZINGMARGINS
value|3601
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_GLYPHTYPE
end_ifndef
begin_define
DECL|macro|TMT_GLYPHTYPE
define|#
directive|define
name|TMT_GLYPHTYPE
value|4012
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_BGTYPE
end_ifndef
begin_define
DECL|macro|TMT_BGTYPE
define|#
directive|define
name|TMT_BGTYPE
value|4001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_TEXTSHADOWTYPE
end_ifndef
begin_define
DECL|macro|TMT_TEXTSHADOWTYPE
define|#
directive|define
name|TMT_TEXTSHADOWTYPE
value|4010
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_BORDERCOLOR
end_ifndef
begin_define
DECL|macro|TMT_BORDERCOLOR
define|#
directive|define
name|TMT_BORDERCOLOR
value|3801
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|BT_IMAGEFILE
end_ifndef
begin_define
DECL|macro|BT_IMAGEFILE
define|#
directive|define
name|BT_IMAGEFILE
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|BT_BORDERFILL
end_ifndef
begin_define
DECL|macro|BT_BORDERFILL
define|#
directive|define
name|BT_BORDERFILL
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|BT_NONE
end_ifndef
begin_define
DECL|macro|BT_NONE
define|#
directive|define
name|BT_NONE
value|2
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_FILLCOLOR
end_ifndef
begin_define
DECL|macro|TMT_FILLCOLOR
define|#
directive|define
name|TMT_FILLCOLOR
value|3802
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TMT_PROGRESSCHUNKSIZE
end_ifndef
begin_define
DECL|macro|TMT_PROGRESSCHUNKSIZE
define|#
directive|define
name|TMT_PROGRESSCHUNKSIZE
value|2411
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TMT_TEXTSHADOWCOLOR is wrongly defined in mingw
end_comment
begin_if
if|#
directive|if
name|TMT_TEXTSHADOWCOLOR
operator|!=
literal|3818
end_if
begin_undef
DECL|macro|TMT_TEXTSHADOWCOLOR
undef|#
directive|undef
name|TMT_TEXTSHADOWCOLOR
end_undef
begin_define
DECL|macro|TMT_TEXTSHADOWCOLOR
define|#
directive|define
name|TMT_TEXTSHADOWCOLOR
value|3818
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|TST_NONE
end_ifndef
begin_define
DECL|macro|TST_NONE
define|#
directive|define
name|TST_NONE
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GT_NONE
end_ifndef
begin_define
DECL|macro|GT_NONE
define|#
directive|define
name|GT_NONE
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GT_IMAGEGLYPH
end_ifndef
begin_define
DECL|macro|GT_IMAGEGLYPH
define|#
directive|define
name|GT_IMAGEGLYPH
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// These defines are missing from the tmschema, but still exist as
end_comment
begin_comment
comment|// states for their parts
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MINBS_INACTIVE
end_ifndef
begin_define
DECL|macro|MINBS_INACTIVE
define|#
directive|define
name|MINBS_INACTIVE
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|MAXBS_INACTIVE
end_ifndef
begin_define
DECL|macro|MAXBS_INACTIVE
define|#
directive|define
name|MAXBS_INACTIVE
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|RBS_INACTIVE
end_ifndef
begin_define
DECL|macro|RBS_INACTIVE
define|#
directive|define
name|RBS_INACTIVE
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HBS_INACTIVE
end_ifndef
begin_define
DECL|macro|HBS_INACTIVE
define|#
directive|define
name|HBS_INACTIVE
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|CBS_INACTIVE
end_ifndef
begin_define
DECL|macro|CBS_INACTIVE
define|#
directive|define
name|CBS_INACTIVE
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Uncomment define below to build debug assisting code, and output
end_comment
begin_comment
comment|// #define DEBUG_XP_STYLE
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_WINDOWSXP
argument_list|)
end_if
begin_comment
comment|// Declarations -----------------------------------------------------------------------------------
end_comment
begin_decl_stmt
name|class
name|XPThemeData
block|{
name|public
label|:
name|XPThemeData
argument_list|(
argument|const QWidget *w =
literal|0
argument_list|,
argument|QPainter *p =
literal|0
argument_list|,
argument|const QString&theme = QString()
argument_list|,
argument|int part =
literal|0
argument_list|,
argument|int state =
literal|0
argument_list|,
argument|const QRect&r = QRect()
argument_list|)
block|:
name|widget
argument_list|(
name|w
argument_list|)
operator|,
name|painter
argument_list|(
name|p
argument_list|)
operator|,
name|name
argument_list|(
name|theme
argument_list|)
operator|,
name|htheme
argument_list|(
literal|0
argument_list|)
operator|,
name|partId
argument_list|(
name|part
argument_list|)
operator|,
name|stateId
argument_list|(
name|state
argument_list|)
operator|,
name|mirrorHorizontally
argument_list|(
name|false
argument_list|)
operator|,
name|mirrorVertically
argument_list|(
name|false
argument_list|)
operator|,
name|noBorder
argument_list|(
name|false
argument_list|)
operator|,
name|noContent
argument_list|(
name|false
argument_list|)
operator|,
name|rotate
argument_list|(
literal|0
argument_list|)
operator|,
name|rect
argument_list|(
argument|r
argument_list|)
block|{}
name|HRGN
name|mask
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
expr_stmt|;
name|HTHEME
name|handle
parameter_list|()
function_decl|;
name|RECT
name|toRECT
parameter_list|(
specifier|const
name|QRect
modifier|&
name|qr
parameter_list|)
function_decl|;
name|bool
name|isValid
parameter_list|()
function_decl|;
specifier|const
name|QWidget
modifier|*
name|widget
decl_stmt|;
name|QPainter
modifier|*
name|painter
decl_stmt|;
name|QString
name|name
decl_stmt|;
name|HTHEME
name|htheme
decl_stmt|;
name|int
name|partId
decl_stmt|;
name|int
name|stateId
decl_stmt|;
name|uint
name|mirrorHorizontally
range|:
literal|1
decl_stmt|;
name|uint
name|mirrorVertically
range|:
literal|1
decl_stmt|;
name|uint
name|noBorder
range|:
literal|1
decl_stmt|;
name|uint
name|noContent
range|:
literal|1
decl_stmt|;
name|uint
name|rotate
decl_stmt|;
name|QRect
name|rect
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|ThemeMapKey
struct|struct
name|ThemeMapKey
block|{
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|partId
name|int
name|partId
decl_stmt|;
DECL|member|stateId
name|int
name|stateId
decl_stmt|;
DECL|member|noBorder
name|bool
name|noBorder
decl_stmt|;
DECL|member|noContent
name|bool
name|noContent
decl_stmt|;
DECL|function|ThemeMapKey
name|ThemeMapKey
argument_list|()
operator|:
name|partId
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|stateId
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
DECL|function|ThemeMapKey
name|ThemeMapKey
argument_list|(
specifier|const
name|XPThemeData
operator|&
name|data
argument_list|)
operator|:
name|name
argument_list|(
name|data
operator|.
name|name
argument_list|)
operator|,
name|partId
argument_list|(
name|data
operator|.
name|partId
argument_list|)
operator|,
name|stateId
argument_list|(
name|data
operator|.
name|stateId
argument_list|)
operator|,
name|noBorder
argument_list|(
name|data
operator|.
name|noBorder
argument_list|)
operator|,
name|noContent
argument_list|(
argument|data.noContent
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|ThemeMapKey
modifier|&
name|key
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|key
operator|.
name|name
argument_list|)
operator|^
name|key
operator|.
name|partId
operator|^
name|key
operator|.
name|stateId
return|;
block|}
end_function
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ThemeMapKey
operator|&
name|k1
operator|,
specifier|const
name|ThemeMapKey
operator|&
name|k2
operator|)
block|{
return|return
name|k1
operator|.
name|name
operator|==
name|k2
operator|.
name|name
operator|&&
name|k1
operator|.
name|partId
operator|==
name|k2
operator|.
name|partId
operator|&&
name|k1
operator|.
name|stateId
operator|==
name|k2
operator|.
name|stateId
return|;
block|}
end_expr_stmt
begin_enum
DECL|enum|AlphaChannelType
enum|enum
name|AlphaChannelType
block|{
DECL|enumerator|UnknownAlpha
name|UnknownAlpha
init|=
operator|-
literal|1
block|,
comment|// Alpha of part& state not yet known
DECL|enumerator|NoAlpha
name|NoAlpha
block|,
comment|// Totally opaque, no need to touch alpha (RGB)
DECL|enumerator|MaskAlpha
name|MaskAlpha
block|,
comment|// Alpha channel must be fixed            (ARGB)
DECL|enumerator|RealAlpha
name|RealAlpha
comment|// Proper alpha values from Windows       (ARGB_Premultiplied)
block|}
enum|;
end_enum
begin_struct
DECL|struct|ThemeMapData
struct|struct
name|ThemeMapData
block|{
DECL|member|alphaType
name|AlphaChannelType
name|alphaType
decl_stmt|;
comment|// Which type of alpha on part& state
DECL|member|dataValid
name|bool
name|dataValid
range|:
literal|1
decl_stmt|;
comment|// Only used to detect if hash value is ok
DECL|member|partIsTransparent
name|bool
name|partIsTransparent
range|:
literal|1
decl_stmt|;
DECL|member|hasAnyData
name|bool
name|hasAnyData
range|:
literal|1
decl_stmt|;
comment|// False = part& state has not data, NOP
DECL|member|hasAlphaChannel
name|bool
name|hasAlphaChannel
range|:
literal|1
decl_stmt|;
comment|// True =  part& state has real Alpha
DECL|member|wasAlphaSwapped
name|bool
name|wasAlphaSwapped
range|:
literal|1
decl_stmt|;
comment|// True =  alpha channel needs to be swapped
DECL|member|hadInvalidAlpha
name|bool
name|hadInvalidAlpha
range|:
literal|1
decl_stmt|;
comment|// True =  alpha channel contained invalid alpha values
DECL|function|ThemeMapData
name|ThemeMapData
argument_list|()
operator|:
name|dataValid
argument_list|(
name|false
argument_list|)
operator|,
name|partIsTransparent
argument_list|(
name|false
argument_list|)
operator|,
name|hasAnyData
argument_list|(
name|false
argument_list|)
operator|,
name|hasAlphaChannel
argument_list|(
name|false
argument_list|)
operator|,
name|wasAlphaSwapped
argument_list|(
name|false
argument_list|)
operator|,
name|hadInvalidAlpha
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QWindowsXPStylePrivate
range|:
name|public
name|QWindowsStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QWindowsXPStyle
argument_list|)
name|public
operator|:
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|HTHEME
operator|>
name|ThemeHandleMap
expr_stmt|;
name|QWindowsXPStylePrivate
argument_list|()
operator|:
name|QWindowsStylePrivate
argument_list|()
block|,
name|hasInitColors
argument_list|(
name|false
argument_list|)
block|,
name|bufferDC
argument_list|(
literal|0
argument_list|)
block|,
name|bufferBitmap
argument_list|(
literal|0
argument_list|)
block|,
name|nullBitmap
argument_list|(
literal|0
argument_list|)
block|,
name|bufferPixels
argument_list|(
literal|0
argument_list|)
block|,
name|bufferW
argument_list|(
literal|0
argument_list|)
block|,
name|bufferH
argument_list|(
literal|0
argument_list|)
block|{
name|init
argument_list|()
block|; }
operator|~
name|QWindowsXPStylePrivate
argument_list|()
block|{
name|cleanup
argument_list|()
block|; }
specifier|static
name|HWND
name|winId
argument_list|(
specifier|const
name|QWidget
operator|*
name|widget
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|init
parameter_list|(
name|bool
name|force
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|cleanup
parameter_list|(
name|bool
name|force
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|cleanupHandleMap
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|QPixmap
modifier|*
name|tabBody
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|HBITMAP
name|buffer
parameter_list|(
name|int
name|w
init|=
literal|0
parameter_list|,
name|int
name|h
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function
name|HDC
name|bufferHDC
parameter_list|()
block|{
return|return
name|bufferDC
return|;
block|}
end_function
begin_function_decl
specifier|static
name|bool
name|resolveSymbols
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|useXP
parameter_list|(
name|bool
name|update
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|isTransparent
parameter_list|(
name|XPThemeData
modifier|&
name|themeData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QRegion
name|region
parameter_list|(
name|XPThemeData
modifier|&
name|themeData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setTransparency
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|XPThemeData
modifier|&
name|themeData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|drawBackground
parameter_list|(
name|XPThemeData
modifier|&
name|themeData
parameter_list|,
name|bool
name|forceFallback
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|drawBackgroundThruNativeBuffer
parameter_list|(
name|XPThemeData
modifier|&
name|themeData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|drawBackgroundDirectly
parameter_list|(
name|XPThemeData
modifier|&
name|themeData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|hasAnyData
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|hasAlphaChannel
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|fixAlphaChannel
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|swapAlphaChannel
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|bool
name|allPixels
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QRgb
name|groupBoxTextColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRgb
name|groupBoxTextColorDisabled
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRgb
name|sliderTickColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|hasInitColors
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|ThemeHandleMap
modifier|*
name|handleMap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIcon
name|dockFloat
decl_stmt|,
name|dockClose
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_XP_STYLE
end_ifdef
begin_function_decl
name|void
name|dumpNativeDIB
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|showProperties
parameter_list|(
name|XPThemeData
modifier|&
name|themeData
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|static
name|QBasicAtomicInt
name|ref
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|bool
name|use_xp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QPixmap
modifier|*
name|tabbody
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHash
operator|<
name|ThemeMapKey
operator|,
name|ThemeMapData
operator|>
name|alphaCache
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|HDC
name|bufferDC
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|HBITMAP
name|bufferBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|HBITMAP
name|nullBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uchar
modifier|*
name|bufferPixels
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|bufferW
decl_stmt|,
name|bufferH
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_WINDOWS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QWINDOWSXPSTYLE_P_H
end_comment
end_unit
