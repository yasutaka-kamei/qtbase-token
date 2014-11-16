begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONT_P_H
end_ifndef
begin_define
DECL|macro|QFONT_P_H
define|#
directive|define
name|QFONT_P_H
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
comment|// of internal files.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|"QtGui/qfont.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qobject.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|"private/qfixed_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// forwards
DECL|variable|QFontCache
name|class
name|QFontCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontEngine
name|class
name|QFontEngine
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QFontDef
struct|struct
name|QFontDef
block|{
DECL|function|QFontDef
specifier|inline
name|QFontDef
argument_list|()
operator|:
name|pointSize
argument_list|(
operator|-
literal|1.0
argument_list|)
operator|,
name|pixelSize
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|styleStrategy
argument_list|(
name|QFont
operator|::
name|PreferDefault
argument_list|)
operator|,
name|styleHint
argument_list|(
name|QFont
operator|::
name|AnyStyle
argument_list|)
operator|,
name|weight
argument_list|(
literal|50
argument_list|)
operator|,
name|fixedPitch
argument_list|(
name|false
argument_list|)
operator|,
name|style
argument_list|(
name|QFont
operator|::
name|StyleNormal
argument_list|)
operator|,
name|stretch
argument_list|(
literal|100
argument_list|)
operator|,
name|hintingPreference
argument_list|(
name|QFont
operator|::
name|PreferDefaultHinting
argument_list|)
operator|,
name|ignorePitch
argument_list|(
name|true
argument_list|)
operator|,
name|fixedPitchComputed
argument_list|(
literal|0
argument_list|)
operator|,
name|reserved
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|member|family
name|QString
name|family
expr_stmt|;
DECL|member|styleName
name|QString
name|styleName
decl_stmt|;
DECL|member|fallBackFamilies
name|QStringList
name|fallBackFamilies
decl_stmt|;
DECL|member|pointSize
name|qreal
name|pointSize
decl_stmt|;
DECL|member|pixelSize
name|qreal
name|pixelSize
decl_stmt|;
DECL|member|styleStrategy
name|uint
name|styleStrategy
range|:
literal|16
decl_stmt|;
DECL|member|styleHint
name|uint
name|styleHint
range|:
literal|8
decl_stmt|;
DECL|member|weight
name|uint
name|weight
range|:
literal|7
decl_stmt|;
comment|// 0-99
DECL|member|fixedPitch
name|uint
name|fixedPitch
range|:
literal|1
decl_stmt|;
DECL|member|style
name|uint
name|style
range|:
literal|2
decl_stmt|;
DECL|member|stretch
name|uint
name|stretch
range|:
literal|12
decl_stmt|;
comment|// 0-4000
DECL|member|hintingPreference
name|uint
name|hintingPreference
range|:
literal|2
decl_stmt|;
DECL|member|ignorePitch
name|uint
name|ignorePitch
range|:
literal|1
decl_stmt|;
DECL|member|fixedPitchComputed
name|uint
name|fixedPitchComputed
range|:
literal|1
decl_stmt|;
comment|// for Mac OS X only
DECL|member|reserved
name|int
name|reserved
range|:
literal|14
decl_stmt|;
comment|// for future extensions
name|bool
name|exactMatch
argument_list|(
specifier|const
name|QFontDef
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFontDef
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|pixelSize
operator|==
name|other
operator|.
name|pixelSize
operator|&&
name|weight
operator|==
name|other
operator|.
name|weight
operator|&&
name|style
operator|==
name|other
operator|.
name|style
operator|&&
name|stretch
operator|==
name|other
operator|.
name|stretch
operator|&&
name|styleHint
operator|==
name|other
operator|.
name|styleHint
operator|&&
name|styleStrategy
operator|==
name|other
operator|.
name|styleStrategy
operator|&&
name|ignorePitch
operator|==
name|other
operator|.
name|ignorePitch
operator|&&
name|fixedPitch
operator|==
name|other
operator|.
name|fixedPitch
operator|&&
name|family
operator|==
name|other
operator|.
name|family
operator|&&
operator|(
name|styleName
operator|.
name|isEmpty
argument_list|()
operator|||
name|other
operator|.
name|styleName
operator|.
name|isEmpty
argument_list|()
operator|||
name|styleName
operator|==
name|other
operator|.
name|styleName
operator|)
operator|&&
name|hintingPreference
operator|==
name|other
operator|.
name|hintingPreference
return|;
block|}
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QFontDef
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|pixelSize
operator|!=
name|other
operator|.
name|pixelSize
condition|)
return|return
name|pixelSize
operator|<
name|other
operator|.
name|pixelSize
return|;
if|if
condition|(
name|weight
operator|!=
name|other
operator|.
name|weight
condition|)
return|return
name|weight
operator|<
name|other
operator|.
name|weight
return|;
if|if
condition|(
name|style
operator|!=
name|other
operator|.
name|style
condition|)
return|return
name|style
operator|<
name|other
operator|.
name|style
return|;
if|if
condition|(
name|stretch
operator|!=
name|other
operator|.
name|stretch
condition|)
return|return
name|stretch
operator|<
name|other
operator|.
name|stretch
return|;
if|if
condition|(
name|styleHint
operator|!=
name|other
operator|.
name|styleHint
condition|)
return|return
name|styleHint
operator|<
name|other
operator|.
name|styleHint
return|;
if|if
condition|(
name|styleStrategy
operator|!=
name|other
operator|.
name|styleStrategy
condition|)
return|return
name|styleStrategy
operator|<
name|other
operator|.
name|styleStrategy
return|;
if|if
condition|(
name|family
operator|!=
name|other
operator|.
name|family
condition|)
return|return
name|family
operator|<
name|other
operator|.
name|family
return|;
if|if
condition|(
operator|!
name|styleName
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|other
operator|.
name|styleName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|styleName
operator|!=
name|other
operator|.
name|styleName
condition|)
return|return
name|styleName
operator|<
name|other
operator|.
name|styleName
return|;
if|if
condition|(
name|hintingPreference
operator|!=
name|other
operator|.
name|hintingPreference
condition|)
return|return
name|hintingPreference
operator|<
name|other
operator|.
name|hintingPreference
return|;
if|if
condition|(
name|ignorePitch
operator|!=
name|other
operator|.
name|ignorePitch
condition|)
return|return
name|ignorePitch
operator|<
name|other
operator|.
name|ignorePitch
return|;
if|if
condition|(
name|fixedPitch
operator|!=
name|other
operator|.
name|fixedPitch
condition|)
return|return
name|fixedPitch
operator|<
name|other
operator|.
name|fixedPitch
return|;
return|return
name|false
return|;
block|}
end_struct
begin_function
unit|};
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fd
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|qHash
argument_list|(
name|qRound64
argument_list|(
name|fd
operator|.
name|pixelSize
operator|*
literal|10000
argument_list|)
argument_list|)
comment|// use only 4 fractional digits
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|weight
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|style
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|stretch
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|styleHint
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|styleStrategy
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|ignorePitch
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|fixedPitch
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|family
argument_list|,
name|seed
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|styleName
argument_list|)
operator|^
name|qHash
argument_list|(
name|fd
operator|.
name|hintingPreference
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|class
name|QFontEngineData
block|{
name|public
label|:
name|QFontEngineData
argument_list|()
expr_stmt|;
operator|~
name|QFontEngineData
argument_list|()
expr_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
specifier|const
name|int
name|fontCacheId
decl_stmt|;
name|QFontEngine
modifier|*
name|engines
index|[
name|QChar
operator|::
name|ScriptCount
index|]
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QFontEngineData
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontPrivate
block|{
name|public
label|:
name|QFontPrivate
argument_list|()
expr_stmt|;
name|QFontPrivate
argument_list|(
specifier|const
name|QFontPrivate
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QFontPrivate
argument_list|()
expr_stmt|;
name|QFontEngine
modifier|*
name|engineForScript
argument_list|(
name|int
name|script
argument_list|)
decl|const
decl_stmt|;
name|void
name|alterCharForCapitalization
argument_list|(
name|QChar
operator|&
name|c
argument_list|)
decl|const
decl_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|QFontDef
name|request
decl_stmt|;
name|mutable
name|QFontEngineData
modifier|*
name|engineData
decl_stmt|;
name|int
name|dpi
decl_stmt|;
name|int
name|screen
decl_stmt|;
name|uint
name|rawMode
range|:
literal|1
decl_stmt|;
name|uint
name|underline
range|:
literal|1
decl_stmt|;
name|uint
name|overline
range|:
literal|1
decl_stmt|;
name|uint
name|strikeOut
range|:
literal|1
decl_stmt|;
name|uint
name|kerning
range|:
literal|1
decl_stmt|;
name|uint
name|capital
range|:
literal|3
decl_stmt|;
name|bool
name|letterSpacingIsAbsolute
range|:
literal|1
decl_stmt|;
name|QFixed
name|letterSpacing
decl_stmt|;
name|QFixed
name|wordSpacing
decl_stmt|;
name|mutable
name|QFontPrivate
modifier|*
name|scFont
decl_stmt|;
name|QFont
name|smallCapsFont
argument_list|()
specifier|const
block|{
return|return
name|QFont
argument_list|(
name|smallCapsFontPrivate
argument_list|()
argument_list|)
return|;
block|}
name|QFontPrivate
operator|*
name|smallCapsFontPrivate
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QFontPrivate
modifier|*
name|get
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
return|return
name|font
operator|.
name|d
operator|.
name|data
argument_list|()
return|;
block|}
name|void
name|resolve
parameter_list|(
name|uint
name|mask
parameter_list|,
specifier|const
name|QFontPrivate
modifier|*
name|other
parameter_list|)
function_decl|;
specifier|static
name|void
name|detachButKeepEngineData
parameter_list|(
name|QFont
modifier|*
name|font
parameter_list|)
function_decl|;
name|private
label|:
name|QFontPrivate
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFontPrivate
operator|&
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QFontCache
range|:
name|public
name|QObject
block|{
name|public
operator|:
comment|// note: these static functions work on a per-thread basis
specifier|static
name|QFontCache
operator|*
name|instance
argument_list|()
block|;
specifier|static
name|void
name|cleanup
argument_list|()
block|;
name|QFontCache
argument_list|()
block|;
operator|~
name|QFontCache
argument_list|()
block|;
name|int
name|id
argument_list|()
specifier|const
block|{
return|return
name|m_id
return|;
block|}
name|void
name|clear
argument_list|()
block|;      struct
name|Key
block|{
name|Key
argument_list|()
operator|:
name|script
argument_list|(
literal|0
argument_list|)
block|,
name|multi
argument_list|(
literal|0
argument_list|)
block|,
name|screen
argument_list|(
literal|0
argument_list|)
block|{ }
name|Key
argument_list|(
argument|const QFontDef&d
argument_list|,
argument|uchar c
argument_list|,
argument|bool m =
literal|0
argument_list|,
argument|uchar s =
literal|0
argument_list|)
operator|:
name|def
argument_list|(
name|d
argument_list|)
block|,
name|script
argument_list|(
name|c
argument_list|)
block|,
name|multi
argument_list|(
name|m
argument_list|)
block|,
name|screen
argument_list|(
argument|s
argument_list|)
block|{ }
name|QFontDef
name|def
block|;
name|uchar
name|script
block|;
name|uchar
name|multi
operator|:
literal|1
block|;
name|uchar
name|screen
operator|:
literal|7
block|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Key
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|script
operator|!=
name|other
operator|.
name|script
condition|)
return|return
name|script
operator|<
name|other
operator|.
name|script
return|;
if|if
condition|(
name|screen
operator|!=
name|other
operator|.
name|screen
condition|)
return|return
name|screen
operator|<
name|other
operator|.
name|screen
return|;
if|if
condition|(
name|multi
operator|!=
name|other
operator|.
name|multi
condition|)
return|return
name|multi
operator|<
name|other
operator|.
name|multi
return|;
end_decl_stmt
begin_if
if|if
condition|(
name|multi
operator|&&
name|def
operator|.
name|fallBackFamilies
operator|.
name|size
argument_list|()
operator|!=
name|other
operator|.
name|def
operator|.
name|fallBackFamilies
operator|.
name|size
argument_list|()
condition|)
return|return
name|def
operator|.
name|fallBackFamilies
operator|.
name|size
argument_list|()
operator|<
name|other
operator|.
name|def
operator|.
name|fallBackFamilies
operator|.
name|size
argument_list|()
return|;
end_if
begin_return
return|return
name|def
operator|<
name|other
operator|.
name|def
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Key
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|script
operator|==
name|other
operator|.
name|script
operator|&&
name|screen
operator|==
name|other
operator|.
name|screen
operator|&&
name|multi
operator|==
name|other
operator|.
name|multi
operator|&&
operator|(
operator|!
name|multi
operator|||
name|def
operator|.
name|fallBackFamilies
operator|==
name|other
operator|.
name|def
operator|.
name|fallBackFamilies
operator|)
operator|&&
name|def
operator|==
name|other
operator|.
name|def
return|;
block|}
end_expr_stmt
begin_comment
unit|};
comment|// QFontEngineData cache
end_comment
begin_typedef
typedef|typedef
name|QMap
operator|<
name|QFontDef
operator|,
name|QFontEngineData
operator|*
operator|>
name|EngineDataCache
expr_stmt|;
end_typedef
begin_decl_stmt
name|EngineDataCache
name|engineDataCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFontEngineData
modifier|*
name|findEngineData
argument_list|(
specifier|const
name|QFontDef
operator|&
name|def
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|insertEngineData
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|def
parameter_list|,
name|QFontEngineData
modifier|*
name|engineData
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// QFontEngine cache
end_comment
begin_struct
struct|struct
name|Engine
block|{
name|Engine
argument_list|()
operator|:
name|data
argument_list|(
literal|0
argument_list|)
operator|,
name|timestamp
argument_list|(
literal|0
argument_list|)
operator|,
name|hits
argument_list|(
literal|0
argument_list|)
block|{ }
name|Engine
argument_list|(
name|QFontEngine
operator|*
name|d
argument_list|)
operator|:
name|data
argument_list|(
name|d
argument_list|)
operator|,
name|timestamp
argument_list|(
literal|0
argument_list|)
operator|,
name|hits
argument_list|(
literal|0
argument_list|)
block|{ }
name|QFontEngine
operator|*
name|data
expr_stmt|;
name|uint
name|timestamp
decl_stmt|;
name|uint
name|hits
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
typedef|typedef
name|QMap
operator|<
name|Key
operator|,
name|Engine
operator|>
name|EngineCache
expr_stmt|;
end_typedef
begin_decl_stmt
name|EngineCache
name|engineCache
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHash
operator|<
name|QFontEngine
operator|*
operator|,
name|int
operator|>
name|engineCacheCount
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QFontEngine
modifier|*
name|findEngine
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateHitCountAndTimeStamp
parameter_list|(
name|Engine
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|insertEngine
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|,
name|QFontEngine
modifier|*
name|engine
parameter_list|,
name|bool
name|insertMulti
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|increaseCost
parameter_list|(
name|uint
name|cost
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|decreaseCost
parameter_list|(
name|uint
name|cost
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|uint
name|min_cost
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|total_cost
decl_stmt|,
name|max_cost
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|current_timestamp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|fast
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|timer_id
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|int
name|m_id
decl_stmt|;
end_decl_stmt
begin_function_decl
unit|};
name|Q_GUI_EXPORT
name|int
name|qt_defaultDpiX
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|int
name|qt_defaultDpiY
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|int
name|qt_defaultDpi
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONT_P_H
end_comment
end_unit
