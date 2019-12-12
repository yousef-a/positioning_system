#pragma once 

#include <cstdint>

template <class T>  

class Vector3D
{
        public:
        
                T x, y, z;

                vec_3d<T> operator + (vec_3d<T> obj)
                {
                        vec_3d<T> res;
                        res.x = x + obj.x;
                        res.y = y + obj.y;
                        res.z = z + obj.z;
                        return res;
                }
                vec_3d<T> operator - (vec_3d<T> obj)
                {
                        vec_3d<T> res;
                        res.x = x - obj.x;
                        res.y = y - obj.y;
                        res.z = z - obj.z;
                        return res;
                }
                vec_3d<T> operator * (vec_3d<T> obj)
                {
                        vec_3d<T> res;
                        res.x = x * obj.x;
                        res.y = y * obj.y;
                        res.z = z * obj.z;
                        return res;
                }
                vec_3d<T> operator * (T tmp)
                {
                        vec_3d<T> res;
                        res.x = this->x * tmp;
                        res.y = this->y * tmp;
                        res.z = this->z * tmp;
                        return res;
                }
                vec_3d<T> operator / (T tmp)
                {
                        vec_3d<T> res;
                        res.x = this->x / tmp;
                        res.y = this->y / tmp;
                        res.z = this->z / tmp;
                        return res;
                }
                void operator = (T tmp)
                {
                        this->x = tmp;
                        this->y = tmp;
                        this->z = tmp;
                }

                template <typename M>
                operator vec_3d<M>()
                {
                        vec_3d<M> tmp;
                        tmp.x = M(this->x);
                        tmp.y = M(this->y);
                        tmp.z = M(this->z);

                        return tmp;
                }

};