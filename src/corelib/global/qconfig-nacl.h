begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_pragma
pragma|#
directive|pragma
name|qt_sync_stop_processing
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_FONTS_ARE_RESOURCES
define|#
directive|define
name|QT_FONTS_ARE_RESOURCES
end_define
begin_comment
comment|/* Data structures */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTDATE
end_ifndef
begin_define
DECL|macro|QT_NO_TEXTDATE
define|#
directive|define
name|QT_NO_TEXTDATE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
end_ifndef
begin_define
DECL|macro|QT_NO_DATESTRING
define|#
directive|define
name|QT_NO_DATESTRING
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Dialogs */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILEDIALOG
end_ifndef
begin_define
DECL|macro|QT_NO_FILEDIALOG
define|#
directive|define
name|QT_NO_FILEDIALOG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
end_ifndef
begin_define
DECL|macro|QT_NO_PRINTDIALOG
define|#
directive|define
name|QT_NO_PRINTDIALOG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTPREVIEWDIALOG
end_ifndef
begin_define
DECL|macro|QT_NO_PRINTPREVIEWDIALOG
define|#
directive|define
name|QT_NO_PRINTPREVIEWDIALOG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* File I/O */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DOM
end_ifndef
begin_define
DECL|macro|QT_NO_DOM
define|#
directive|define
name|QT_NO_DOM
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
end_ifndef
begin_define
DECL|macro|QT_NO_FILESYSTEMWATCHER
define|#
directive|define
name|QT_NO_FILESYSTEMWATCHER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
end_ifndef
begin_define
DECL|macro|QT_NO_FSFILEENGINE
define|#
directive|define
name|QT_NO_FSFILEENGINE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMMODEL
end_ifndef
begin_define
DECL|macro|QT_NO_FILESYSTEMMODEL
define|#
directive|define
name|QT_NO_FILESYSTEMMODEL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMMODEL
end_ifndef
begin_define
DECL|macro|QT_NO_FILESYSTEMMODEL
define|#
directive|define
name|QT_NO_FILESYSTEMMODEL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_define
DECL|macro|QT_NO_PROCESS
define|#
directive|define
name|QT_NO_PROCESS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEMPORARYFILE
end_ifndef
begin_define
DECL|macro|QT_NO_TEMPORARYFILE
define|#
directive|define
name|QT_NO_TEMPORARYFILE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
end_ifndef
begin_define
DECL|macro|QT_NO_SETTINGS
define|#
directive|define
name|QT_NO_SETTINGS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_define
DECL|macro|QT_NO_LIBRARY
define|#
directive|define
name|QT_NO_LIBRARY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Fonts */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_QPF2
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_QPF2
define|#
directive|define
name|QT_NO_QWS_QPF2
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Images */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMATPLUGIN
end_ifndef
begin_define
DECL|macro|QT_NO_IMAGEFORMATPLUGIN
define|#
directive|define
name|QT_NO_IMAGEFORMATPLUGIN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGE_HEURISTIC_MASK
end_ifndef
begin_define
DECL|macro|QT_NO_IMAGE_HEURISTIC_MASK
define|#
directive|define
name|QT_NO_IMAGE_HEURISTIC_MASK
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MOVIE
end_ifndef
begin_define
DECL|macro|QT_NO_MOVIE
define|#
directive|define
name|QT_NO_MOVIE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Internationalization */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BIG_CODECS
end_ifndef
begin_define
DECL|macro|QT_NO_BIG_CODECS
define|#
directive|define
name|QT_NO_BIG_CODECS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_INPUTMETHODS
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_INPUTMETHODS
define|#
directive|define
name|QT_NO_QWS_INPUTMETHODS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_define
DECL|macro|QT_NO_TEXTCODEC
define|#
directive|define
name|QT_NO_TEXTCODEC
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CODECS
end_ifndef
begin_define
DECL|macro|QT_NO_CODECS
define|#
directive|define
name|QT_NO_CODECS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
end_ifndef
begin_define
DECL|macro|QT_NO_TRANSLATION
define|#
directive|define
name|QT_NO_TRANSLATION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION_UTF8
end_ifndef
begin_define
DECL|macro|QT_NO_TRANSLATION_UTF8
define|#
directive|define
name|QT_NO_TRANSLATION_UTF8
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ItemViews */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIRMODEL
end_ifndef
begin_define
DECL|macro|QT_NO_DIRMODEL
define|#
directive|define
name|QT_NO_DIRMODEL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Kernel */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_define
DECL|macro|QT_NO_CLIPBOARD
define|#
directive|define
name|QT_NO_CLIPBOARD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CSSPARSER
end_ifndef
begin_define
DECL|macro|QT_NO_CSSPARSER
define|#
directive|define
name|QT_NO_CSSPARSER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_define
DECL|macro|QT_NO_CURSOR
define|#
directive|define
name|QT_NO_CURSOR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_define
DECL|macro|QT_NO_DRAGANDDROP
define|#
directive|define
name|QT_NO_DRAGANDDROP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EFFECTS
end_ifndef
begin_define
DECL|macro|QT_NO_EFFECTS
define|#
directive|define
name|QT_NO_EFFECTS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
end_ifndef
begin_define
DECL|macro|QT_NO_SESSIONMANAGER
define|#
directive|define
name|QT_NO_SESSIONMANAGER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHAREDMEMORY
end_ifndef
begin_define
DECL|macro|QT_NO_SHAREDMEMORY
define|#
directive|define
name|QT_NO_SHAREDMEMORY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SOUND
end_ifndef
begin_define
DECL|macro|QT_NO_SOUND
define|#
directive|define
name|QT_NO_SOUND
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCALE
end_ifndef
begin_define
DECL|macro|QT_NO_SYSTEMSEMAPHORE
define|#
directive|define
name|QT_NO_SYSTEMSEMAPHORE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
end_ifndef
begin_define
DECL|macro|QT_NO_SYSTEMSEMAPHORE
define|#
directive|define
name|QT_NO_SYSTEMSEMAPHORE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
end_ifndef
begin_define
DECL|macro|QT_NO_TABLETEVENT
define|#
directive|define
name|QT_NO_TABLETEVENT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CRASHHANDLER
end_ifndef
begin_define
DECL|macro|QT_NO_CRASHHANDLER
define|#
directive|define
name|QT_NO_CRASHHANDLER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_define
DECL|macro|QT_NO_CONCURRENT
define|#
directive|define
name|QT_NO_CONCURRENT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XMLSTREAM
end_ifndef
begin_define
DECL|macro|QT_NO_XMLSTREAM
define|#
directive|define
name|QT_NO_XMLSTREAM
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XMLSTREAMREADER
end_ifndef
begin_define
DECL|macro|QT_NO_XMLSTREAMREADER
define|#
directive|define
name|QT_NO_XMLSTREAMREADER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XMLSTREAMWRITER
end_ifndef
begin_define
DECL|macro|QT_NO_XMLSTREAMWRITER
define|#
directive|define
name|QT_NO_XMLSTREAMWRITER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Networking */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COP
end_ifndef
begin_define
DECL|macro|QT_NO_COP
define|#
directive|define
name|QT_NO_COP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HOSTINFO
end_ifndef
begin_define
DECL|macro|QT_NO_HOSTINFO
define|#
directive|define
name|QT_NO_HOSTINFO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_define
DECL|macro|QT_NO_HTTP
define|#
directive|define
name|QT_NO_HTTP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_define
DECL|macro|QT_NO_NETWORKPROXY
define|#
directive|define
name|QT_NO_NETWORKPROXY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SOCKS5
end_ifndef
begin_define
DECL|macro|QT_NO_SOCKS5
define|#
directive|define
name|QT_NO_SOCKS5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
end_ifndef
begin_define
DECL|macro|QT_NO_UDPSOCKET
define|#
directive|define
name|QT_NO_UDPSOCKET
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_URLINFO
end_ifndef
begin_define
DECL|macro|QT_NO_URLINFO
define|#
directive|define
name|QT_NO_URLINFO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FTP
end_ifndef
begin_define
DECL|macro|QT_NO_FTP
define|#
directive|define
name|QT_NO_FTP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Painting */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COLORNAMES
end_ifndef
begin_define
DECL|macro|QT_NO_COLORNAMES
define|#
directive|define
name|QT_NO_COLORNAMES
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIRECTPAINTER
end_ifndef
begin_define
DECL|macro|QT_NO_DIRECTPAINTER
define|#
directive|define
name|QT_NO_DIRECTPAINTER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PAINTONSCREEN
end_ifndef
begin_define
DECL|macro|QT_NO_PAINTONSCREEN
define|#
directive|define
name|QT_NO_PAINTONSCREEN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PAINT_DEBUG
end_ifndef
begin_define
DECL|macro|QT_NO_PAINT_DEBUG
define|#
directive|define
name|QT_NO_PAINT_DEBUG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PICTURE
end_ifndef
begin_define
DECL|macro|QT_NO_PICTURE
define|#
directive|define
name|QT_NO_PICTURE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_define
DECL|macro|QT_NO_PRINTER
define|#
directive|define
name|QT_NO_PRINTER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CUPS
end_ifndef
begin_define
DECL|macro|QT_NO_CUPS
define|#
directive|define
name|QT_NO_CUPS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Qt for Embedded Linux */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWSEMBEDWIDGET
end_ifndef
begin_define
DECL|macro|QT_NO_QWSEMBEDWIDGET
define|#
directive|define
name|QT_NO_QWSEMBEDWIDGET
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_ALPHA_CURSOR
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_ALPHA_CURSOR
define|#
directive|define
name|QT_NO_QWS_ALPHA_CURSOR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_CURSOR
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_CURSOR
define|#
directive|define
name|QT_NO_QWS_CURSOR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_DEFAULT
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_DECORATION_DEFAULT
define|#
directive|define
name|QT_NO_QWS_DECORATION_DEFAULT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_STYLED
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_DECORATION_STYLED
define|#
directive|define
name|QT_NO_QWS_DECORATION_STYLED
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_WINDOWS
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_DECORATION_WINDOWS
define|#
directive|define
name|QT_NO_QWS_DECORATION_WINDOWS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MANAGER
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_MANAGER
define|#
directive|define
name|QT_NO_QWS_MANAGER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_KEYBOARD
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_KEYBOARD
define|#
directive|define
name|QT_NO_QWS_KEYBOARD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MOUSE
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_MOUSE
define|#
directive|define
name|QT_NO_QWS_MOUSE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MOUSE_AUTO
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_MOUSE_AUTO
define|#
directive|define
name|QT_NO_QWS_MOUSE_AUTO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MOUSE_MANUAL
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_MOUSE_MANUAL
define|#
directive|define
name|QT_NO_QWS_MOUSE_MANUAL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MULTIPROCESS
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_MULTIPROCESS
define|#
directive|define
name|QT_NO_QWS_MULTIPROCESS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_SOUNDSERVER
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_SOUNDSERVER
define|#
directive|define
name|QT_NO_QWS_SOUNDSERVER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_PROPERTIES
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_PROPERTIES
define|#
directive|define
name|QT_NO_QWS_PROPERTIES
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_PROXYSCREEN
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_PROXYSCREEN
define|#
directive|define
name|QT_NO_QWS_PROXYSCREEN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_DYNAMICSCREENTRANSFORMATION
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_DYNAMICSCREENTRANSFORMATION
define|#
directive|define
name|QT_NO_QWS_DYNAMICSCREENTRANSFORMATION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_LINUXFB
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_LINUXFB
define|#
directive|define
name|QT_NO_QWS_LINUXFB
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MOUSE_PC
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_MOUSE_PC
define|#
directive|define
name|QT_NO_QWS_MOUSE_PC
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MOUSE_LINUXTP
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_MOUSE_LINUXTP
define|#
directive|define
name|QT_NO_QWS_MOUSE_LINUXTP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_QPF
end_ifndef
begin_define
DECL|macro|QT_NO_QWS_QPF
define|#
directive|define
name|QT_NO_QWS_QPF
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* SVG */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SVG
end_ifndef
begin_define
DECL|macro|QT_NO_SVG
define|#
directive|define
name|QT_NO_SVG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSSVGITEM
end_ifndef
begin_define
DECL|macro|QT_NO_GRAPHICSSVGITEM
define|#
directive|define
name|QT_NO_GRAPHICSSVGITEM
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SVGGENERATOR
end_ifndef
begin_define
DECL|macro|QT_NO_SVGGENERATOR
define|#
directive|define
name|QT_NO_SVGGENERATOR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SVGRENDERER
end_ifndef
begin_define
DECL|macro|QT_NO_SVGRENDERER
define|#
directive|define
name|QT_NO_SVGRENDERER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SVGWIDGET
end_ifndef
begin_define
DECL|macro|QT_NO_SVGWIDGET
define|#
directive|define
name|QT_NO_SVGWIDGET
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Styles */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_MOTIF
end_ifndef
begin_define
DECL|macro|QT_NO_STYLE_MOTIF
define|#
directive|define
name|QT_NO_STYLE_MOTIF
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_CDE
end_ifndef
begin_define
DECL|macro|QT_NO_STYLE_CDE
define|#
directive|define
name|QT_NO_STYLE_CDE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
end_ifndef
begin_define
DECL|macro|QT_NO_STYLE_STYLESHEET
define|#
directive|define
name|QT_NO_STYLE_STYLESHEET
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSCE
end_ifndef
begin_define
DECL|macro|QT_NO_STYLE_WINDOWSCE
define|#
directive|define
name|QT_NO_STYLE_WINDOWSCE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSMOBILE
end_ifndef
begin_define
DECL|macro|QT_NO_STYLE_WINDOWSMOBILE
define|#
directive|define
name|QT_NO_STYLE_WINDOWSMOBILE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSVISTA
end_ifndef
begin_define
DECL|macro|QT_NO_STYLE_WINDOWSVISTA
define|#
directive|define
name|QT_NO_STYLE_WINDOWSVISTA
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSXP
end_ifndef
begin_define
DECL|macro|QT_NO_STYLE_WINDOWSXP
define|#
directive|define
name|QT_NO_STYLE_WINDOWSXP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Utilities */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_define
DECL|macro|QT_NO_ACCESSIBILITY
define|#
directive|define
name|QT_NO_ACCESSIBILITY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
end_ifndef
begin_define
DECL|macro|QT_NO_COMPLETER
define|#
directive|define
name|QT_NO_COMPLETER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DESKTOPSERVICES
end_ifndef
begin_define
DECL|macro|QT_NO_DESKTOPSERVICES
define|#
directive|define
name|QT_NO_DESKTOPSERVICES
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCRIPT
end_ifndef
begin_define
DECL|macro|QT_NO_SCRIPT
define|#
directive|define
name|QT_NO_SCRIPT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_define
DECL|macro|QT_NO_SYSTEMTRAYICON
define|#
directive|define
name|QT_NO_SYSTEMTRAYICON
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Windows */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WIN_ACTIVEQT
end_ifndef
begin_define
DECL|macro|QT_NO_WIN_ACTIVEQT
define|#
directive|define
name|QT_NO_WIN_ACTIVEQT
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
