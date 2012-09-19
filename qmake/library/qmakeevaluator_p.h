begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMAKEEVALUATOR_P_H
end_ifndef
begin_define
DECL|macro|QMAKEEVALUATOR_P_H
define|#
directive|define
name|QMAKEEVALUATOR_P_H
end_define
begin_include
include|#
directive|include
file|"proitems.h"
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_define
DECL|macro|debugMsg
define|#
directive|define
name|debugMsg
value|if (!m_debugLevel) {} else debugMsgInternal
end_define
begin_define
DECL|macro|traceMsg
define|#
directive|define
name|traceMsg
value|if (!m_debugLevel) {} else traceMsgInternal
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|PROEVALUATOR_DEBUG
end_ifdef
begin_define
DECL|macro|dbgBool
define|#
directive|define
name|dbgBool
parameter_list|(
name|b
parameter_list|)
value|(b ? "true" : "false")
end_define
begin_define
DECL|macro|dbgReturn
define|#
directive|define
name|dbgReturn
parameter_list|(
name|r
parameter_list|)
define|\
value|(r == ReturnError ? "error" : \      r == ReturnBreak ? "break" : \      r == ReturnNext ? "next" : \      r == ReturnReturn ? "return" : \      "<invalid>")
end_define
begin_define
DECL|macro|dbgKey
define|#
directive|define
name|dbgKey
parameter_list|(
name|s
parameter_list|)
value|qPrintable(s.toString().toQString())
end_define
begin_define
DECL|macro|dbgStr
define|#
directive|define
name|dbgStr
parameter_list|(
name|s
parameter_list|)
value|qPrintable(formatValue(s, true))
end_define
begin_define
DECL|macro|dbgStrList
define|#
directive|define
name|dbgStrList
parameter_list|(
name|s
parameter_list|)
value|qPrintable(formatValueList(s))
end_define
begin_define
DECL|macro|dbgSepStrList
define|#
directive|define
name|dbgSepStrList
parameter_list|(
name|s
parameter_list|)
value|qPrintable(formatValueList(s, true))
end_define
begin_define
DECL|macro|dbgStrListList
define|#
directive|define
name|dbgStrListList
parameter_list|(
name|s
parameter_list|)
value|qPrintable(formatValueListList(s))
end_define
begin_define
DECL|macro|dbgQStr
define|#
directive|define
name|dbgQStr
parameter_list|(
name|s
parameter_list|)
value|dbgStr(ProString(s))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|dbgBool
define|#
directive|define
name|dbgBool
parameter_list|(
name|b
parameter_list|)
value|0
end_define
begin_define
DECL|macro|dbgReturn
define|#
directive|define
name|dbgReturn
parameter_list|(
name|r
parameter_list|)
value|0
end_define
begin_define
DECL|macro|dbgKey
define|#
directive|define
name|dbgKey
parameter_list|(
name|s
parameter_list|)
value|0
end_define
begin_define
DECL|macro|dbgStr
define|#
directive|define
name|dbgStr
parameter_list|(
name|s
parameter_list|)
value|0
end_define
begin_define
DECL|macro|dbgStrList
define|#
directive|define
name|dbgStrList
parameter_list|(
name|s
parameter_list|)
value|0
end_define
begin_define
DECL|macro|dbgSepStrList
define|#
directive|define
name|dbgSepStrList
parameter_list|(
name|s
parameter_list|)
value|0
end_define
begin_define
DECL|macro|dbgStrListList
define|#
directive|define
name|dbgStrListList
parameter_list|(
name|s
parameter_list|)
value|0
end_define
begin_define
DECL|macro|dbgQStr
define|#
directive|define
name|dbgQStr
parameter_list|(
name|s
parameter_list|)
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QMakeInternal
block|{
struct|struct
name|QMakeStatics
block|{
name|QString
name|field_sep
decl_stmt|;
name|QString
name|strtrue
decl_stmt|;
name|QString
name|strfalse
decl_stmt|;
name|ProKey
name|strCONFIG
decl_stmt|;
name|ProKey
name|strARGS
decl_stmt|;
name|QString
name|strDot
decl_stmt|;
name|QString
name|strDotDot
decl_stmt|;
name|QString
name|strever
decl_stmt|;
name|QString
name|strforever
decl_stmt|;
name|QString
name|strhost_build
decl_stmt|;
name|ProKey
name|strTEMPLATE
decl_stmt|;
ifdef|#
directive|ifdef
name|PROEVALUATOR_FULL
name|ProKey
name|strREQUIRES
decl_stmt|;
endif|#
directive|endif
name|QHash
operator|<
name|ProKey
operator|,
name|int
operator|>
name|expands
expr_stmt|;
name|QHash
operator|<
name|ProKey
operator|,
name|int
operator|>
name|functions
expr_stmt|;
name|QHash
operator|<
name|ProKey
operator|,
name|ProKey
operator|>
name|varMap
expr_stmt|;
name|ProStringList
name|fakeValue
decl_stmt|;
block|}
struct|;
specifier|extern
name|QMakeStatics
name|statics
decl_stmt|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMAKEEVALUATOR_P_H
end_comment
end_unit
