
#ifndef CASADI_NLPSOLVER_STABILIZEDSQP_EXPORT_H
#define CASADI_NLPSOLVER_STABILIZEDSQP_EXPORT_H

#ifdef CASADI_NLPSOLVER_STABILIZEDSQP_STATIC_DEFINE
#  define CASADI_NLPSOLVER_STABILIZEDSQP_EXPORT
#  define CASADI_NLPSOLVER_STABILIZEDSQP_NO_EXPORT
#else
#  ifndef CASADI_NLPSOLVER_STABILIZEDSQP_EXPORT
#    ifdef casadi_nlpsolver_stabilizedsqp_EXPORTS
        /* We are building this library */
#      define CASADI_NLPSOLVER_STABILIZEDSQP_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define CASADI_NLPSOLVER_STABILIZEDSQP_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef CASADI_NLPSOLVER_STABILIZEDSQP_NO_EXPORT
#    define CASADI_NLPSOLVER_STABILIZEDSQP_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef CASADI_NLPSOLVER_STABILIZEDSQP_DEPRECATED
#  define CASADI_NLPSOLVER_STABILIZEDSQP_DEPRECATED __attribute__ ((__deprecated__))
#  define CASADI_NLPSOLVER_STABILIZEDSQP_DEPRECATED_EXPORT CASADI_NLPSOLVER_STABILIZEDSQP_EXPORT __attribute__ ((__deprecated__))
#  define CASADI_NLPSOLVER_STABILIZEDSQP_DEPRECATED_NO_EXPORT CASADI_NLPSOLVER_STABILIZEDSQP_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define CASADI_NLPSOLVER_STABILIZEDSQP_NO_DEPRECATED
#endif

#endif
