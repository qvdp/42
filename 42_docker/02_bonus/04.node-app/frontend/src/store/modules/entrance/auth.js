import { AUTH_REQUEST, AUTH_ERROR, AUTH_SUCCESS, AUTH_LOGOUT, AUTH_LOGOUT_SUCCESS } from './actions/entrance.actions'
import HTTP from '@/utils/http-constant'

const state = {
  token: localStorage.getItem('user-token') || ''
}

const getters = {
  isAuthenticated: state => !!state.token
}

const actions = {
  [AUTH_REQUEST]: ({ commit, dispatch }, data) => {
    return new Promise((resolve, reject) => {
      commit(AUTH_REQUEST)
      HTTP({
        method: 'PUT',
        url: '/api/v1/auth',
        data: {
          emailAddress: data.emailAddress,
          password: data.password
        }
      })
        .then(() => {
          localStorage.setItem('user-token', "is-authenticated")
          commit(AUTH_SUCCESS)
          resolve()
        })
        .catch(() => {
          commit(AUTH_ERROR)
          dispatch(AUTH_LOGOUT)
          reject()
        })
    })
  },
  [AUTH_LOGOUT]: ({ commit }) => {
    return new Promise((resolve) => {
      commit(AUTH_LOGOUT)
      setTimeout(() => {
        localStorage.removeItem('user-token')
        commit(AUTH_LOGOUT_SUCCESS)
        resolve()
      }, 1.5 * 1000)
    })
  }
}

const mutations = {
  [AUTH_REQUEST]: () => {
    console.log('AUTH - loading')
  },
  [AUTH_SUCCESS]: (state) => {
    console.log('AUTH - success')
    state.token = localStorage.getItem('user-token')
  },
  [AUTH_ERROR]: () => {
    console.log('AUTH - error')
  },
  [AUTH_LOGOUT]: () => {
    console.log('LOGOUT - loading')
  },
  [AUTH_LOGOUT_SUCCESS]: (state) => {
    console.log('LOGOUT - success')
    state.token = ''
  }
}

export default {
  state,
  getters,
  actions,
  mutations
}
