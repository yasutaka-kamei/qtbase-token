begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|"object.h"
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_enum
enum|enum
block|{
DECL|enumerator|CreationDeletionBenckmarkConstant
name|CreationDeletionBenckmarkConstant
init|=
literal|34567
block|,
DECL|enumerator|SignalsAndSlotsBenchmarkConstant
name|SignalsAndSlotsBenchmarkConstant
init|=
literal|456789
block|}
enum|;
end_enum
begin_class
DECL|class|QObjectBenchmark
class|class
name|QObjectBenchmark
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|signal_slot_benchmark
parameter_list|()
function_decl|;
name|void
name|signal_slot_benchmark_data
parameter_list|()
function_decl|;
name|void
name|qproperty_benchmark_data
parameter_list|()
function_decl|;
name|void
name|qproperty_benchmark
parameter_list|()
function_decl|;
name|void
name|dynamic_property_benchmark
parameter_list|()
function_decl|;
name|void
name|connect_disconnect_benchmark_data
parameter_list|()
function_decl|;
name|void
name|connect_disconnect_benchmark
parameter_list|()
function_decl|;
name|void
name|receiver_destroyed_benchmark
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_struct
DECL|struct|Functor
struct|struct
name|Functor
block|{
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|()
block|{}
block|}
struct|;
end_struct
begin_function
DECL|function|signal_slot_benchmark_data
name|void
name|QObjectBenchmark
operator|::
name|signal_slot_benchmark_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"simple function"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"single signal/slot"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"multi signal/slot"
argument_list|)
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unconnected signal"
argument_list|)
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"single signal/ptr"
argument_list|)
operator|<<
literal|4
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"functor"
argument_list|)
operator|<<
literal|5
expr_stmt|;
block|}
end_function
begin_function
DECL|function|signal_slot_benchmark
name|void
name|QObjectBenchmark
operator|::
name|signal_slot_benchmark
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|Object
name|singleObject
decl_stmt|;
name|Object
name|multiObject
decl_stmt|;
name|Functor
name|functor
decl_stmt|;
name|singleObject
operator|.
name|setObjectName
argument_list|(
literal|"single"
argument_list|)
expr_stmt|;
name|multiObject
operator|.
name|setObjectName
argument_list|(
literal|"multi"
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
literal|5
condition|)
block|{
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|singleObject
argument_list|,
operator|&
name|Object
operator|::
name|signal0
argument_list|,
name|functor
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|4
condition|)
block|{
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|singleObject
argument_list|,
operator|&
name|Object
operator|::
name|signal0
argument_list|,
operator|&
name|singleObject
argument_list|,
operator|&
name|Object
operator|::
name|slot0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|singleObject
operator|.
name|connect
argument_list|(
operator|&
name|singleObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal0
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot0
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal0
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot0
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal1()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal1
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot1
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal2()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal2
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot2
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal3()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal3
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot3
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal4()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal4
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot4
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal5()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal5
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot5
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal6()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal6
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot6
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal7()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal7
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot7
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal8()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal8
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot8
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// multiObject.connect(&multiObject, SIGNAL(signal0()), SLOT(signal9()));
name|multiObject
operator|.
name|connect
argument_list|(
operator|&
name|multiObject
argument_list|,
name|SIGNAL
argument_list|(
name|signal9
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|slot9
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
literal|0
condition|)
block|{
name|QBENCHMARK
block|{
name|singleObject
operator|.
name|slot0
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|1
condition|)
block|{
name|QBENCHMARK
block|{
name|singleObject
operator|.
name|emitSignal0
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|2
condition|)
block|{
name|QBENCHMARK
block|{
name|multiObject
operator|.
name|emitSignal0
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|3
condition|)
block|{
name|QBENCHMARK
block|{
name|singleObject
operator|.
name|emitSignal1
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|4
operator|||
name|type
operator|==
literal|5
condition|)
block|{
name|QBENCHMARK
block|{
name|singleObject
operator|.
name|emitSignal0
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|qproperty_benchmark_data
name|void
name|QObjectBenchmark
operator|::
name|qproperty_benchmark_data
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
DECL|function|qproperty_benchmark
name|void
name|QObjectBenchmark
operator|::
name|qproperty_benchmark
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
name|QTreeView
name|obj
decl_stmt|;
name|QVariant
name|v
init|=
name|obj
operator|.
name|property
argument_list|(
name|p
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|obj
operator|.
name|setProperty
argument_list|(
name|p
argument_list|,
name|v
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|obj
operator|.
name|property
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dynamic_property_benchmark
name|void
name|QObjectBenchmark
operator|::
name|dynamic_property_benchmark
parameter_list|()
block|{
name|QTreeView
name|obj
decl_stmt|;
name|QBENCHMARK
block|{
name|obj
operator|.
name|setProperty
argument_list|(
literal|"myProperty"
argument_list|,
literal|123
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|obj
operator|.
name|property
argument_list|(
literal|"myProperty"
argument_list|)
expr_stmt|;
name|obj
operator|.
name|setProperty
argument_list|(
literal|"myOtherProperty"
argument_list|,
literal|123
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|obj
operator|.
name|property
argument_list|(
literal|"myOtherProperty"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|connect_disconnect_benchmark_data
name|void
name|QObjectBenchmark
operator|::
name|connect_disconnect_benchmark_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"normalized signature"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unormalized signature"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function pointer"
argument_list|)
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"normalized signature/handle"
argument_list|)
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unormalized signature/handle"
argument_list|)
operator|<<
literal|4
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"function pointer/handle"
argument_list|)
operator|<<
literal|5
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"functor/handle"
argument_list|)
operator|<<
literal|6
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connect_disconnect_benchmark
name|void
name|QObjectBenchmark
operator|::
name|connect_disconnect_benchmark
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|type
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
literal|0
case|:
block|{
name|QTreeView
name|obj
decl_stmt|;
name|QBENCHMARK
block|{
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|obj
argument_list|,
name|SIGNAL
argument_list|(
name|viewportEntered
argument_list|()
argument_list|)
argument_list|,
operator|&
name|obj
argument_list|,
name|SLOT
argument_list|(
name|expandAll
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|disconnect
argument_list|(
operator|&
name|obj
argument_list|,
name|SIGNAL
argument_list|(
name|viewportEntered
argument_list|()
argument_list|)
argument_list|,
operator|&
name|obj
argument_list|,
name|SLOT
argument_list|(
name|expandAll
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|1
case|:
block|{
name|QTreeView
name|obj
decl_stmt|;
name|QBENCHMARK
block|{
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|obj
argument_list|,
name|SIGNAL
argument_list|(
name|viewportEntered
argument_list|(  )
argument_list|)
argument_list|,
operator|&
name|obj
argument_list|,
name|SLOT
argument_list|(
name|expandAll
argument_list|(  )
argument_list|)
argument_list|)
expr_stmt|;
comment|// sic: non-normalised
name|QObject
operator|::
name|disconnect
argument_list|(
operator|&
name|obj
argument_list|,
name|SIGNAL
argument_list|(
name|viewportEntered
argument_list|(  )
argument_list|)
argument_list|,
operator|&
name|obj
argument_list|,
name|SLOT
argument_list|(
name|expandAll
argument_list|(  )
argument_list|)
argument_list|)
expr_stmt|;
comment|// sic: non-normalised
block|}
block|}
break|break;
case|case
literal|2
case|:
block|{
name|QTreeView
name|obj
decl_stmt|;
name|QBENCHMARK
block|{
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|obj
argument_list|,
operator|&
name|QAbstractItemView
operator|::
name|viewportEntered
argument_list|,
operator|&
name|obj
argument_list|,
operator|&
name|QTreeView
operator|::
name|expandAll
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|disconnect
argument_list|(
operator|&
name|obj
argument_list|,
operator|&
name|QAbstractItemView
operator|::
name|viewportEntered
argument_list|,
operator|&
name|obj
argument_list|,
operator|&
name|QTreeView
operator|::
name|expandAll
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|3
case|:
block|{
name|QTreeView
name|obj
decl_stmt|;
name|QBENCHMARK
block|{
name|QObject
operator|::
name|disconnect
argument_list|(
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|obj
argument_list|,
name|SIGNAL
argument_list|(
name|viewportEntered
argument_list|()
argument_list|)
argument_list|,
operator|&
name|obj
argument_list|,
name|SLOT
argument_list|(
name|expandAll
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|4
case|:
block|{
name|QTreeView
name|obj
decl_stmt|;
name|QBENCHMARK
block|{
name|QObject
operator|::
name|disconnect
argument_list|(
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|obj
argument_list|,
name|SIGNAL
argument_list|(
name|viewportEntered
argument_list|(  )
argument_list|)
argument_list|,
operator|&
name|obj
argument_list|,
name|SLOT
argument_list|(
name|expandAll
argument_list|(  )
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// sic: non-normalised
block|}
block|}
break|break;
case|case
literal|5
case|:
block|{
name|QTreeView
name|obj
decl_stmt|;
name|QBENCHMARK
block|{
name|QObject
operator|::
name|disconnect
argument_list|(
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|obj
argument_list|,
operator|&
name|QAbstractItemView
operator|::
name|viewportEntered
argument_list|,
operator|&
name|obj
argument_list|,
operator|&
name|QTreeView
operator|::
name|expandAll
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|6
case|:
block|{
name|QTreeView
name|obj
decl_stmt|;
name|Functor
name|functor
decl_stmt|;
name|QBENCHMARK
block|{
name|QObject
operator|::
name|disconnect
argument_list|(
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|obj
argument_list|,
operator|&
name|QAbstractItemView
operator|::
name|viewportEntered
argument_list|,
name|functor
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
block|}
block|}
end_function
begin_function
DECL|function|receiver_destroyed_benchmark
name|void
name|QObjectBenchmark
operator|::
name|receiver_destroyed_benchmark
parameter_list|()
block|{
name|Object
name|sender
decl_stmt|;
name|QBENCHMARK
block|{
name|Object
name|receiver
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|sender
argument_list|,
operator|&
name|Object
operator|::
name|signal0
argument_list|,
operator|&
name|receiver
argument_list|,
operator|&
name|Object
operator|::
name|slot0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|QObjectBenchmark
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
