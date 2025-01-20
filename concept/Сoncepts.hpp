#ifndef CONCEPTS_H
#define CONCEPTS_H
#include <concepts>

template <typename T,typename BinaryOp>
concept Associative = requires(T a, T b, T c, BinaryOp op)
{
    {op(op(a,b),c)} -> std::same_as<T>;
    {op(op(a,b),c)==op(a,op(b,c))};
};

template <typename T, typename BinaryOp>
concept Commutative=requires(T a, T b, BinaryOp op)
{
    {op(a,b)} ->std::same_as<T>;
    {op(a,b)== op(b,a) };
};

template <typename T, typename BinaryOp, typename Elements>
concept HasIdentity = requires(T a, BinaryOp op)
{
    {op(a,Elements::zero())} ->std::same_as<T>;
    {op(a,Elements::zero()) ==a };
    {op(Elements::zero(), a) == a };
};

template<typename T,typename BinaryOp, typename UnaryOp, typename Elements>
concept HasInverse = requires(T a,BinaryOp op,UnaryOp inv)
{
    {op(a,inv(a)) }->std::same_as<T>;
    { op(a,inv(a))==Elements::zero()};
    {op(inv(a),a) == Elements::zero() };
};

template <typename T,typename Add, typename Mul>
concept Distributive = requires(T a, T b, T c, Add add, Mul mul)
{
    {mul(a,add(b,c)) }->std::same_as<T>;
    {mul(a,add(b,c)) == add(mul(a,b),mul(a,c)) };
    {mul(add(b,c),a) == add(mul(b,a),mul(c,a)) };
};

template <typename T, typename Add,typename Mul, typename UnaryMinus, typename Elements>
concept Ring =
    Associative<T, Add> &&
    Commutative<T,Add>  &&
    HasIdentity<T, Add, Elements> &&
    HasInverse<T, Add, UnaryMinus, Elements> &&
    Associative<T, Mul> &&
    Distributive<T, Add, Mul> &&
    HasIdentity<T, Mul, Elements>;


#endif //CONCEPTS_H
