begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MODEL_H
end_ifndef
begin_define
DECL|macro|MODEL_H
define|#
directive|define
name|MODEL_H
end_define
begin_include
include|#
directive|include
file|<QAbstractItemModel>
end_include
begin_include
include|#
directive|include
file|<QFileIconProvider>
end_include
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_decl_stmt
name|class
name|Model
range|:
name|public
name|QAbstractItemModel
block|{
name|Q_OBJECT
name|public
operator|:
name|Model
argument_list|(
argument|int rows
argument_list|,
argument|int columns
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|Model
argument_list|()
block|;
name|QModelIndex
name|index
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&child
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
expr|struct
name|Node
block|{
name|Node
argument_list|(
name|Node
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|parent
argument_list|(
name|parent
argument_list|)
block|,
name|children
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|Node
argument_list|()
block|{
name|delete
name|children
block|; }
name|Node
operator|*
name|parent
block|;
name|QVector
operator|<
name|Node
operator|>
operator|*
name|children
block|;     }
block|;
name|Node
operator|*
name|node
argument_list|(
argument|int row
argument_list|,
argument|Node *parent
argument_list|)
specifier|const
block|;
name|Node
operator|*
name|parent
argument_list|(
argument|Node *child
argument_list|)
specifier|const
block|;
name|int
name|row
argument_list|(
argument|Node *node
argument_list|)
specifier|const
block|;
name|QIcon
name|services
block|;
name|int
name|rc
block|;
name|int
name|cc
block|;
name|QVector
operator|<
name|Node
operator|>
operator|*
name|tree
block|;
name|QFileIconProvider
name|iconProvider
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MODEL_H
end_comment
end_unit
