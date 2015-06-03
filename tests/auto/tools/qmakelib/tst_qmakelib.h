begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qmakeevaluator.h>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QProcessEnvironment>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_decl_stmt
name|class
name|tst_qmakelib
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|tst_qmakelib
argument_list|()
block|{}
name|virtual
operator|~
name|tst_qmakelib
argument_list|()
block|{}
name|private
name|slots
operator|:
name|void
name|initTestCase
argument_list|()
block|;
name|void
name|cleanupTestCase
argument_list|()
block|;
name|void
name|quoteArgUnix_data
argument_list|()
block|;
name|void
name|quoteArgUnix
argument_list|()
block|;
name|void
name|quoteArgWin_data
argument_list|()
block|;
name|void
name|quoteArgWin
argument_list|()
block|;
name|void
name|pathUtils
argument_list|()
block|;
name|void
name|proString
argument_list|()
block|;
name|void
name|proStringList
argument_list|()
block|;
name|void
name|proParser_data
argument_list|()
block|;
name|void
name|proParser
argument_list|()
block|;
name|void
name|proEval_data
argument_list|()
block|;
name|void
name|proEval
argument_list|()
block|;
name|private
operator|:
name|void
name|addParseOperators
argument_list|()
block|;
name|void
name|addParseValues
argument_list|()
block|;
name|void
name|addParseConditions
argument_list|()
block|;
name|void
name|addParseControlStatements
argument_list|()
block|;
name|void
name|addParseBraces
argument_list|()
block|;
name|void
name|addParseCustomFunctions
argument_list|()
block|;
name|void
name|addParseAbuse
argument_list|()
block|;
name|void
name|addAssignments
argument_list|()
block|;
name|void
name|addExpansions
argument_list|()
block|;
name|void
name|addControlStructs
argument_list|()
block|;
name|void
name|addReplaceFunctions
argument_list|(
specifier|const
name|QString
operator|&
name|qindir
argument_list|)
block|;
name|void
name|addTestFunctions
argument_list|(
specifier|const
name|QString
operator|&
name|qindir
argument_list|)
block|;
name|QProcessEnvironment
name|m_env
block|;
name|QHash
operator|<
name|ProKey
block|,
name|ProString
operator|>
name|m_prop
block|;
name|QString
name|m_indir
block|,
name|m_outdir
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMakeTestHandler
range|:
name|public
name|QMakeHandler
block|{
name|public
operator|:
name|QMakeTestHandler
argument_list|()
operator|:
name|QMakeHandler
argument_list|()
block|,
name|printed
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
name|void
name|message
argument_list|(
argument|int type
argument_list|,
argument|const QString&msg
argument_list|,
argument|const QString&fileName
argument_list|,
argument|int lineNo
argument_list|)
block|{
name|print
argument_list|(
name|fileName
argument_list|,
name|lineNo
argument_list|,
name|type
argument_list|,
name|msg
argument_list|)
block|; }
name|virtual
name|void
name|fileMessage
argument_list|(
argument|const QString&msg
argument_list|)
block|{
name|doPrint
argument_list|(
name|msg
argument_list|)
block|; }
name|virtual
name|void
name|aboutToEval
argument_list|(
argument|ProFile *
argument_list|,
argument|ProFile *
argument_list|,
argument|EvalFileType
argument_list|)
block|{}
name|virtual
name|void
name|doneWithEval
argument_list|(
argument|ProFile *
argument_list|)
block|{}
name|void
name|setExpectedMessages
argument_list|(
argument|const QStringList&msgs
argument_list|)
block|{
name|expected
operator|=
name|msgs
block|; }
name|QStringList
name|expectedMessages
argument_list|()
specifier|const
block|{
return|return
name|expected
return|;
block|}
name|bool
name|printedMessages
argument_list|()
specifier|const
block|{
return|return
name|printed
return|;
block|}
name|private
operator|:
name|void
name|print
argument_list|(
argument|const QString&fileName
argument_list|,
argument|int lineNo
argument_list|,
argument|int type
argument_list|,
argument|const QString&msg
argument_list|)
block|;
name|void
name|doPrint
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|)
block|;
name|QStringList
name|expected
block|;
name|bool
name|printed
block|; }
decl_stmt|;
end_decl_stmt
end_unit
