begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qfont.h>
end_include
begin_include
include|#
directive|include
file|<private/qfont_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_class
DECL|class|tst_QFontCache
class|class
name|tst_QFontCache
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QFontCache
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QFontCache
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|engineData_data
parameter_list|()
function_decl|;
name|void
name|engineData
parameter_list|()
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
end_ifdef
begin_function_decl
name|QT_BEGIN_NAMESPACE
comment|// qfontdatabase.cpp
name|Q_AUTOTEST_EXPORT
name|void
name|qt_setQtEnableTestFont
parameter_list|(
name|bool
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// qfontengine.cpp
end_comment
begin_function_decl
name|Q_AUTOTEST_EXPORT
name|void
name|QFontEngine_startCollectingEngines
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_AUTOTEST_EXPORT
name|QList
argument_list|<
name|QFontEngine
modifier|*
argument_list|>
name|QFontEngine_stopCollectingEngines
parameter_list|()
function_decl|;
end_function_decl
begin_function
name|QT_END_NAMESPACE
endif|#
directive|endif
DECL|function|tst_QFontCache
name|tst_QFontCache
operator|::
name|tst_QFontCache
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~tst_QFontCache
name|tst_QFontCache
operator|::
name|~
name|tst_QFontCache
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|engineData_data
name|void
name|tst_QFontCache
operator|::
name|engineData_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"family"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"cacheKey"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unquoted-family-name"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Times New Roman"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Times New Roman"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"quoted-family-name"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"'Times New Roman'"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Times New Roman"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"multiple"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid, Times New Roman"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid,Times New Roman"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"multiple spaces"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid,  Times New Roman "
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid,Times New Roman"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"multiple spaces quotes"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"'invalid',  Times New Roman "
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid,Times New Roman"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"multiple2"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid, Times New Roman  , foobar, 'baz'"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid,Times New Roman,foobar,baz"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid spaces"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid spaces, Times New Roman "
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid spaces,Times New Roman"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid spaces quotes"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"'invalid spaces', 'Times New Roman' "
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"invalid spaces,Times New Roman"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|engineData
name|void
name|tst_QFontCache
operator|::
name|engineData
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|family
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|cacheKey
argument_list|)
expr_stmt|;
name|QFont
name|f
argument_list|(
name|family
argument_list|)
decl_stmt|;
name|f
operator|.
name|exactMatch
argument_list|()
expr_stmt|;
comment|// loads engine
name|QFontPrivate
modifier|*
name|d
init|=
name|QFontPrivate
operator|::
name|get
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|QFontDef
name|req
init|=
name|d
operator|->
name|request
decl_stmt|;
comment|// copy-pasted from QFontDatabase::load(), to engineer the cache key
if|if
condition|(
name|req
operator|.
name|pixelSize
operator|==
operator|-
literal|1
condition|)
block|{
name|req
operator|.
name|pixelSize
operator|=
name|std
operator|::
name|floor
argument_list|(
operator|(
operator|(
name|req
operator|.
name|pointSize
operator|*
name|d
operator|->
name|dpi
operator|)
operator|/
literal|72
operator|)
operator|*
literal|100
operator|+
literal|0.5
argument_list|)
operator|/
literal|100
expr_stmt|;
name|req
operator|.
name|pixelSize
operator|=
name|qRound
argument_list|(
name|req
operator|.
name|pixelSize
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|req
operator|.
name|pointSize
operator|<
literal|0
condition|)
name|req
operator|.
name|pointSize
operator|=
name|req
operator|.
name|pixelSize
operator|*
literal|72.0
operator|/
name|d
operator|->
name|dpi
expr_stmt|;
if|if
condition|(
name|req
operator|.
name|stretch
operator|==
literal|0
condition|)
name|req
operator|.
name|stretch
operator|=
literal|100
expr_stmt|;
name|req
operator|.
name|family
operator|=
name|cacheKey
expr_stmt|;
name|QFontEngineData
modifier|*
name|engineData
init|=
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|findEngineData
argument_list|(
name|req
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|engineData
argument_list|,
name|QFontPrivate
operator|::
name|get
argument_list|(
name|f
argument_list|)
operator|->
name|engineData
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|tst_QFontCache
operator|::
name|clear
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
name|QFontEngine_startCollectingEngines
argument_list|()
expr_stmt|;
else|#
directive|else
comment|// must not crash, at very least ;)
endif|#
directive|endif
name|QFontEngine
modifier|*
name|fontEngine
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
block|{
comment|// we're never caching the box (and the "test") font engines
comment|// let's ensure we're not leaking them as well as the cached ones
name|qt_setQtEnableTestFont
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QFont
name|f
decl_stmt|;
name|f
operator|.
name|setFamily
argument_list|(
literal|"__Qt__Box__Engine__"
argument_list|)
expr_stmt|;
name|f
operator|.
name|exactMatch
argument_list|()
expr_stmt|;
comment|// loads engine
block|}
endif|#
directive|endif
block|{
name|QFontDatabase
name|db
decl_stmt|;
name|QFont
name|f
decl_stmt|;
name|f
operator|.
name|setStyleHint
argument_list|(
name|QFont
operator|::
name|Serif
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|familyForHint
argument_list|(
name|f
operator|.
name|defaultFamily
argument_list|()
argument_list|)
decl_stmt|;
comment|// it should at least return a family that is available
name|QVERIFY
argument_list|(
name|db
operator|.
name|hasFamily
argument_list|(
name|familyForHint
argument_list|)
argument_list|)
expr_stmt|;
name|f
operator|.
name|exactMatch
argument_list|()
expr_stmt|;
comment|// loads engine
name|fontEngine
operator|=
name|QFontPrivate
operator|::
name|get
argument_list|(
name|f
argument_list|)
operator|->
name|engineForScript
argument_list|(
name|QChar
operator|::
name|Script_Common
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fontEngine
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|engineCacheCount
operator|.
name|value
argument_list|(
name|fontEngine
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|// ensure it is cached
comment|// acquire the engine to use it somewhere else:
comment|// (e.g. like the we do in QFontSubset() or like QRawFont does in fromFont())
name|fontEngine
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
comment|// cache the engine once again; there is a special case when the engine is cached more than once
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|insertEngine
argument_list|(
name|QFontCache
operator|::
name|Key
argument_list|(
name|QFontDef
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|fontEngine
argument_list|)
expr_stmt|;
block|}
comment|// use it:
comment|// e.g. fontEngine->stringToCMap(..);
comment|// and whilst it is alive, don't hesitate to add/remove the app-local fonts:
comment|// (QFontDatabase::{add,remove}ApplicationFont() clears the cache)
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|// release the acquired engine:
if|if
condition|(
name|fontEngine
condition|)
block|{
if|if
condition|(
operator|!
name|fontEngine
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|fontEngine
expr_stmt|;
name|fontEngine
operator|=
literal|0
expr_stmt|;
block|}
comment|// we may even exit the application now:
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|cleanup
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
name|QList
argument_list|<
name|QFontEngine
modifier|*
argument_list|>
name|leakedEngines
init|=
name|QFontEngine_stopCollectingEngines
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
name|leakedEngines
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qWarning
argument_list|()
operator|<<
name|i
operator|<<
name|leakedEngines
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|<<
name|leakedEngines
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|ref
operator|.
name|load
argument_list|()
expr_stmt|;
comment|// and we are not leaking!
name|QCOMPARE
argument_list|(
name|leakedEngines
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFontCache
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfontcache.moc"
end_include
end_unit
