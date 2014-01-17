begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PARSE_BOOST_H
end_ifndef
begin_define
DECL|macro|PARSE_BOOST_H
define|#
directive|define
name|PARSE_BOOST_H
end_define
begin_include
include|#
directive|include
file|<boost/aligned_storage.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/any.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/array.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/assert.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/assign.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/bind.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/blank_fwd.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/blank.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/call_traits.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/cast.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/checked_delete.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/compressed_pair.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/concept_archetype.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/concept_check.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/config.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/crc.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/cstdint.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/cstdlib.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/current_function.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/dynamic_bitset_fwd.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/dynamic_bitset.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/enable_shared_from_this.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/format.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/functional.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/function_equal.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/function.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/function_output_iterator.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/generator_iterator.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/get_pointer.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/implicit_cast.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/indirect_reference.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/integer_fwd.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/integer.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/integer_traits.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/intrusive_ptr.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/io_fwd.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/iterator_adaptors.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/iterator.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/last_value.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/lexical_cast.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/limits.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/math_fwd.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/mem_fn.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/multi_array.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/next_prior.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/noncopyable.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/nondet_random.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/none.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/non_type.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/operators.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/optional.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/pfto.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/pointee.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/preprocessor.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/progress.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/property_map.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/property_map_iterator.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/random.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/range.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/rational.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/ref.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/scoped_array.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/scoped_ptr.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/shared_array.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/shared_container_iterator.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/shared_ptr.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/smart_cast.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/smart_ptr.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/spirit.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/state_saver.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/static_assert.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/static_warning.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/strong_typedef.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/throw_exception.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/timer.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/token_functions.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/token_iterator.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/tokenizer.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/type.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/type_traits.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/utility.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/variant.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/vector_property_map.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/version.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/visit_each.hpp>
end_include
begin_include
include|#
directive|include
file|<boost/weak_ptr.hpp>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PARSE_BOOST_H
end_comment
end_unit
