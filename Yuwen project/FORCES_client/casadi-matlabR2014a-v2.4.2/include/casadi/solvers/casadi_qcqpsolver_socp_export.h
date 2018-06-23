
#ifndef CASADI_QCQPSOLVER_SOCP_EXPORT_H
#define CASADI_QCQPSOLVER_SOCP_EXPORT_H

#ifdef CASADI_QCQPSOLVER_SOCP_STATIC_DEFINE
#  define CASADI_QCQPSOLVER_SOCP_EXPORT
#  define CASADI_QCQPSOLVER_SOCP_NO_EXPORT
#else
#  ifndef CASADI_QCQPSOLVER_SOCP_EXPORT
#    ifdef casadi_qcqpsolver_socp_EXPORTS
        /* We are building this library */
#      define CASADI_QCQPSOLVER_SOCP_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define CASADI_QCQPSOLVER_SOCP_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef CASADI_QCQPSOLVER_SOCP_NO_EXPORT
#    define CASADI_QCQPSOLVER_SOCP_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef CASADI_QCQPSOLVER_SOCP_DEPRECATED
#  define CASADI_QCQPSOLVER_SOCP_DEPRECATED __attribute__ ((__deprecated__))
#  define CASADI_QCQPSOLVER_SOCP_DEPRECATED_EXPORT CASADI_QCQPSOLVER_SOCP_EXPORT __attribute__ ((__deprecated__))
#  define CASADI_QCQPSOLVER_SOCP_DEPRECATED_NO_EXPORT CASADI_QCQPSOLVER_SOCP_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define CASADI_QCQPSOLVER_SOCP_NO_DEPRECATED
#endif

#endif
