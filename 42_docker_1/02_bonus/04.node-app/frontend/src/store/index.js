import Vue from 'vue'
import Vuex from 'vuex'

// Entrance section
import auth from './modules/entrance/auth'

Vue.use(Vuex)

const debug = process.env.NODE_ENV !== 'production'

export default new Vuex.Store({
  modules: {
    auth
  },
  strict: debug
})
