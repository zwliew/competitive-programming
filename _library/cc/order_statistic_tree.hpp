#if !defined(ORDER_STATISTIC_TREE_HPP) && !defined(__clang__) &&               \
    defined(__GNUG__)
#define ORDER_STATISTIC_TREE_HPP

#include <ext/pb_ds/assoc_container.hpp>

namespace ost {
template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map =
    __gnu_pbds::tree<K, V, Comp, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;
} // namespace ost

#endif // ORDER_STATISTIC_TREE_HPP
