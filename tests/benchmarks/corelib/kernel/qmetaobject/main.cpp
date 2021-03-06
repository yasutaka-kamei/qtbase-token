begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTreeView>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
DECL|class|LotsOfSignals
class|class
name|LotsOfSignals
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|LotsOfSignals
name|LotsOfSignals
parameter_list|()
block|{}
signals|signals:
name|void
name|extraSignal1
parameter_list|()
function_decl|;
name|void
name|extraSignal2
parameter_list|()
function_decl|;
name|void
name|extraSignal3
parameter_list|()
function_decl|;
name|void
name|extraSignal4
parameter_list|()
function_decl|;
name|void
name|extraSignal5
parameter_list|()
function_decl|;
name|void
name|extraSignal6
parameter_list|()
function_decl|;
name|void
name|extraSignal7
parameter_list|()
function_decl|;
name|void
name|extraSignal8
parameter_list|()
function_decl|;
name|void
name|extraSignal9
parameter_list|()
function_decl|;
name|void
name|extraSignal10
parameter_list|()
function_decl|;
name|void
name|extraSignal12
parameter_list|()
function_decl|;
name|void
name|extraSignal13
parameter_list|()
function_decl|;
name|void
name|extraSignal14
parameter_list|()
function_decl|;
name|void
name|extraSignal15
parameter_list|()
function_decl|;
name|void
name|extraSignal16
parameter_list|()
function_decl|;
name|void
name|extraSignal17
parameter_list|()
function_decl|;
name|void
name|extraSignal18
parameter_list|()
function_decl|;
name|void
name|extraSignal19
parameter_list|()
function_decl|;
name|void
name|extraSignal20
parameter_list|()
function_decl|;
name|void
name|extraSignal21
parameter_list|()
function_decl|;
name|void
name|extraSignal22
parameter_list|()
function_decl|;
name|void
name|extraSignal23
parameter_list|()
function_decl|;
name|void
name|extraSignal24
parameter_list|()
function_decl|;
name|void
name|extraSignal25
parameter_list|()
function_decl|;
name|void
name|extraSignal26
parameter_list|()
function_decl|;
name|void
name|extraSignal27
parameter_list|()
function_decl|;
name|void
name|extraSignal28
parameter_list|()
function_decl|;
name|void
name|extraSignal29
parameter_list|()
function_decl|;
name|void
name|extraSignal30
parameter_list|()
function_decl|;
name|void
name|extraSignal31
parameter_list|()
function_decl|;
name|void
name|extraSignal32
parameter_list|()
function_decl|;
name|void
name|extraSignal33
parameter_list|()
function_decl|;
name|void
name|extraSignal34
parameter_list|()
function_decl|;
name|void
name|extraSignal35
parameter_list|()
function_decl|;
name|void
name|extraSignal36
parameter_list|()
function_decl|;
name|void
name|extraSignal37
parameter_list|()
function_decl|;
name|void
name|extraSignal38
parameter_list|()
function_decl|;
name|void
name|extraSignal39
parameter_list|()
function_decl|;
name|void
name|extraSignal40
parameter_list|()
function_decl|;
name|void
name|extraSignal41
parameter_list|()
function_decl|;
name|void
name|extraSignal42
parameter_list|()
function_decl|;
name|void
name|extraSignal43
parameter_list|()
function_decl|;
name|void
name|extraSignal44
parameter_list|()
function_decl|;
name|void
name|extraSignal45
parameter_list|()
function_decl|;
name|void
name|extraSignal46
parameter_list|()
function_decl|;
name|void
name|extraSignal47
parameter_list|()
function_decl|;
name|void
name|extraSignal48
parameter_list|()
function_decl|;
name|void
name|extraSignal49
parameter_list|()
function_decl|;
name|void
name|extraSignal50
parameter_list|()
function_decl|;
name|void
name|extraSignal51
parameter_list|()
function_decl|;
name|void
name|extraSignal52
parameter_list|()
function_decl|;
name|void
name|extraSignal53
parameter_list|()
function_decl|;
name|void
name|extraSignal54
parameter_list|()
function_decl|;
name|void
name|extraSignal55
parameter_list|()
function_decl|;
name|void
name|extraSignal56
parameter_list|()
function_decl|;
name|void
name|extraSignal57
parameter_list|()
function_decl|;
name|void
name|extraSignal58
parameter_list|()
function_decl|;
name|void
name|extraSignal59
parameter_list|()
function_decl|;
name|void
name|extraSignal60
parameter_list|()
function_decl|;
name|void
name|extraSignal61
parameter_list|()
function_decl|;
name|void
name|extraSignal62
parameter_list|()
function_decl|;
name|void
name|extraSignal63
parameter_list|()
function_decl|;
name|void
name|extraSignal64
parameter_list|()
function_decl|;
name|void
name|extraSignal65
parameter_list|()
function_decl|;
name|void
name|extraSignal66
parameter_list|()
function_decl|;
name|void
name|extraSignal67
parameter_list|()
function_decl|;
name|void
name|extraSignal68
parameter_list|()
function_decl|;
name|void
name|extraSignal69
parameter_list|()
function_decl|;
name|void
name|extraSignal70
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|tst_qmetaobject
class|class
name|tst_qmetaobject
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|indexOfProperty_data
parameter_list|()
function_decl|;
name|void
name|indexOfProperty
parameter_list|()
function_decl|;
name|void
name|indexOfMethod_data
parameter_list|()
function_decl|;
name|void
name|indexOfMethod
parameter_list|()
function_decl|;
name|void
name|indexOfSignal_data
parameter_list|()
function_decl|;
name|void
name|indexOfSignal
parameter_list|()
function_decl|;
name|void
name|indexOfSlot_data
parameter_list|()
function_decl|;
name|void
name|indexOfSlot
parameter_list|()
function_decl|;
name|void
name|unconnected_data
parameter_list|()
function_decl|;
name|void
name|unconnected
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_qmetaobject
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_qmetaobject
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|indexOfProperty_data
name|void
name|tst_qmetaobject
operator|::
name|indexOfProperty_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"name"
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|QTreeView
operator|::
name|staticMetaObject
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
name|mo
operator|->
name|propertyCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QMetaProperty
name|prop
init|=
name|mo
operator|->
name|property
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|prop
operator|.
name|name
argument_list|()
argument_list|)
operator|<<
name|QByteArray
argument_list|(
name|prop
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|indexOfProperty
name|void
name|tst_qmetaobject
operator|::
name|indexOfProperty
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|name
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|p
init|=
name|name
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|QTreeView
operator|::
name|staticMetaObject
decl_stmt|;
name|QBENCHMARK
block|{
operator|(
name|void
operator|)
name|mo
operator|->
name|indexOfProperty
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|indexOfMethod_data
name|void
name|tst_qmetaobject
operator|::
name|indexOfMethod_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"method"
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|QTreeView
operator|::
name|staticMetaObject
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
name|mo
operator|->
name|methodCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QMetaMethod
name|method
init|=
name|mo
operator|->
name|method
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QByteArray
name|sig
init|=
name|method
operator|.
name|methodSignature
argument_list|()
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|sig
argument_list|)
operator|<<
name|sig
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|indexOfMethod
name|void
name|tst_qmetaobject
operator|::
name|indexOfMethod
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|method
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|p
init|=
name|method
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|QTreeView
operator|::
name|staticMetaObject
decl_stmt|;
name|QBENCHMARK
block|{
operator|(
name|void
operator|)
name|mo
operator|->
name|indexOfMethod
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|indexOfSignal_data
name|void
name|tst_qmetaobject
operator|::
name|indexOfSignal_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"signal"
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|QTreeView
operator|::
name|staticMetaObject
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
name|mo
operator|->
name|methodCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QMetaMethod
name|method
init|=
name|mo
operator|->
name|method
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|method
operator|.
name|methodType
argument_list|()
operator|!=
name|QMetaMethod
operator|::
name|Signal
condition|)
continue|continue;
name|QByteArray
name|sig
init|=
name|method
operator|.
name|methodSignature
argument_list|()
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|sig
argument_list|)
operator|<<
name|sig
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|indexOfSignal
name|void
name|tst_qmetaobject
operator|::
name|indexOfSignal
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|signal
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|p
init|=
name|signal
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|QTreeView
operator|::
name|staticMetaObject
decl_stmt|;
name|QBENCHMARK
block|{
operator|(
name|void
operator|)
name|mo
operator|->
name|indexOfSignal
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|indexOfSlot_data
name|void
name|tst_qmetaobject
operator|::
name|indexOfSlot_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"slot"
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|QTreeView
operator|::
name|staticMetaObject
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
name|mo
operator|->
name|methodCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QMetaMethod
name|method
init|=
name|mo
operator|->
name|method
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|method
operator|.
name|methodType
argument_list|()
operator|!=
name|QMetaMethod
operator|::
name|Slot
condition|)
continue|continue;
name|QByteArray
name|sig
init|=
name|method
operator|.
name|methodSignature
argument_list|()
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|sig
argument_list|)
operator|<<
name|sig
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|indexOfSlot
name|void
name|tst_qmetaobject
operator|::
name|indexOfSlot
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|slot
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|p
init|=
name|slot
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
operator|&
name|QTreeView
operator|::
name|staticMetaObject
decl_stmt|;
name|QBENCHMARK
block|{
operator|(
name|void
operator|)
name|mo
operator|->
name|indexOfSlot
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|unconnected_data
name|void
name|tst_qmetaobject
operator|::
name|unconnected_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"signal_index"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"signal--9"
argument_list|)
operator|<<
literal|9
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"signal--32"
argument_list|)
operator|<<
literal|32
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"signal--33"
argument_list|)
operator|<<
literal|33
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"signal--64"
argument_list|)
operator|<<
literal|64
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"signal--65"
argument_list|)
operator|<<
literal|65
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"signal--70"
argument_list|)
operator|<<
literal|70
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unconnected
name|void
name|tst_qmetaobject
operator|::
name|unconnected
parameter_list|()
block|{
name|LotsOfSignals
modifier|*
name|obj
init|=
operator|new
name|LotsOfSignals
decl_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|signal_index
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|obj
operator|->
name|metaObject
argument_list|()
operator|->
name|methodCount
argument_list|()
operator|==
literal|73
argument_list|)
expr_stmt|;
name|void
modifier|*
name|v
decl_stmt|;
name|QBENCHMARK
block|{
comment|//+1 because QObject has one slot
name|QMetaObject
operator|::
name|metacall
argument_list|(
name|obj
argument_list|,
name|QMetaObject
operator|::
name|InvokeMetaMethod
argument_list|,
name|signal_index
operator|+
literal|1
argument_list|,
operator|&
name|v
argument_list|)
expr_stmt|;
block|}
operator|delete
name|obj
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qmetaobject
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
