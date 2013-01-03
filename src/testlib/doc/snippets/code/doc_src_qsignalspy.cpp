begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|box
name|QCheckBox
modifier|*
name|box
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSignalSpy
name|spy
argument_list|(
name|box
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// do something that triggers the signal
end_comment
begin_expr_stmt
name|box
operator|->
name|animateClick
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// make sure the signal was emitted exactly one time
end_comment
begin_decl_stmt
DECL|variable|arguments
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
init|=
name|spy
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|arguments
comment|// take the first signal
end_comment
begin_expr_stmt
name|QVERIFY
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toBool
argument_list|()
operator|==
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// verify the first argument
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
name|QSignalSpy
name|spy
argument_list|(
name|myCustomObject
argument_list|,
name|SIGNAL
argument_list|(
name|mySignal
argument_list|(
name|int
argument_list|,
name|QString
argument_list|,
name|double
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|myCustomObject
operator|->
name|doSomething
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// trigger emission of the signal
end_comment
begin_decl_stmt
DECL|variable|arguments
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
init|=
name|spy
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QVERIFY
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Int
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVERIFY
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|QString
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVERIFY
argument_list|(
name|arguments
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|double
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|qRegisterMetaType
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
literal|"QModelIndex"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|spy
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|whatever
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|// get the first argument from the first received signal:
end_comment
begin_decl_stmt
DECL|variable|result
name|QModelIndex
name|result
init|=
name|qvariant_cast
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
name|spy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
name|QSignalSpy
name|spy
argument_list|(
name|myPushButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_expr_stmt
name|QVERIFY
argument_list|(
name|spy
operator|.
name|wait
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
end_unit
