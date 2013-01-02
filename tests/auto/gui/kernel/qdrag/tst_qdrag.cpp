begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdrag.h>
end_include
begin_class
DECL|class|tst_QDrag
class|class
name|tst_QDrag
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QDrag
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QDrag
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QDrag
name|tst_QDrag
operator|::
name|tst_QDrag
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QDrag
name|tst_QDrag
operator|::
name|~
name|tst_QDrag
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QDrag
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QDrag
name|obj1
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// QMimeData * QDrag::mimeData()
comment|// void QDrag::setMimeData(QMimeData *)
name|QMimeData
modifier|*
name|var1
init|=
operator|new
name|QMimeData
decl_stmt|;
name|obj1
operator|.
name|setMimeData
argument_list|(
name|var1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var1
argument_list|,
name|obj1
operator|.
name|mimeData
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMimeData
argument_list|(
name|var1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var1
argument_list|,
name|obj1
operator|.
name|mimeData
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMimeData
argument_list|(
operator|(
name|QMimeData
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QMimeData
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|mimeData
argument_list|()
argument_list|)
expr_stmt|;
comment|// delete var1; // No delete, since QDrag takes ownership
name|Qt
operator|::
name|DropAction
name|result
init|=
name|obj1
operator|.
name|start
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|Qt
operator|::
name|IgnoreAction
argument_list|)
expr_stmt|;
name|result
operator|=
name|obj1
operator|.
name|start
argument_list|(
name|Qt
operator|::
name|MoveAction
operator||
name|Qt
operator|::
name|LinkAction
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|Qt
operator|::
name|IgnoreAction
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDrag
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdrag.moc"
end_include
end_unit
