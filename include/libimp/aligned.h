/**
 * \file libimp/aligned.h
 * \author mutouyun (orz@orzz.org)
 * \brief Defines the type suitable for use as uninitialized storage for types of given type.
 * \date 2023-05-20
 */
#pragma once

#include <array>

#include "libimp/def.h"
#include "libimp/byte.h"

LIBIMP_NAMESPACE_BEG_

/**
 * \brief The type suitable for use as uninitialized storage for types of given type.
 *        std::aligned_storage is deprecated in C++23, so we define our own.
 * \tparam T The type to be aligned.
 * \tparam AlignT The alignment of the type.
 * \see https://en.cppreference.com/w/cpp/types/aligned_storage
 *      https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p1413r3.pdf
 */
template <typename T, std::size_t AlignT = alignof(T)>
class aligned {
  alignas(AlignT) std::array<::LIBIMP::byte, sizeof(T)> storage_;

public:
  /**
   * \brief Returns a pointer to the aligned storage.
   * \return A pointer to the aligned storage.
   */
  T *ptr() noexcept {
    return reinterpret_cast<T *>(storage_.data());
  }

  /**
   * \brief Returns a pointer to the aligned storage.
   * \return A pointer to the aligned storage.
   */
  T const *ptr() const noexcept {
    return reinterpret_cast<const T *>(storage_.data());
  }

  /**
   * \brief Returns a reference to the aligned storage.
   * \return A reference to the aligned storage.
   */
  T &ref() noexcept {
    return *ptr();
  }

  /**
   * \brief Returns a reference to the aligned storage.
   * \return A reference to the aligned storage.
   */
  T const &ref() const noexcept {
    return *ptr();
  }
};

LIBIMP_NAMESPACE_END_
