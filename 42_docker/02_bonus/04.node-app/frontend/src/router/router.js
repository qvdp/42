import Vue from 'vue'
import Router from 'vue-router'
import store from '../store'

// --------------------------------------------------------------------------
//  ||  Navatigation Guards definition
//  \/  (Auth status, User role and Entrance finalization)
// --------------------------------------------------------------------------

const ifAuthenticated = (to, from, next) => {
  if (store.getters.isAuthenticated) {
    console.log('NAV GUARD (ifAuthenticated)- User is Authenticated')
    next()
    return
  }
  console.log('NAV GUARD (ifAuthenticated)- User isn\'t Authenticated')
  next({ name: 'Home' })
}

const ifNotAuthenticated = (to, from, next) => {
  if (!store.getters.isAuthenticated) {
    next()
    return
  }
  console.log('NAV GUARD (ifNotAuthenticated)- User is Authenticated')
  next({ name: 'Private' })
}

// --------------------------------------------------------------------------
//  ||  Routing definitions
//  \/
// --------------------------------------------------------------------------

Vue.use(Router)

export default new Router({
  base: '/',
  mode: 'history',
  scrollBehavior (to, from, savedPosition) {
    if (to.matched.some(m => m.meta.disableScroll)) {

    } else if (to.hash) {
      return { selector: to.hash }
    } else {
      return { x: 0, y: 0 }
    }
  },
  routes: [

    /**************************
    *                         *
    *       P U B L I C       *
    *                         *
    **************************/

    { path: '/home', redirect: { name: 'Home' } },
    {
      path: '/',
      name: 'Home',
      component: resolve => {
        require(['@/views/Home.vue'], resolve)
      }
    },

    /**************************
    *                         *
    *      P R I V A T E      *
    *                         *
    **************************/

    {
      path: '/private',
      name: 'Private',
      component: resolve => {
        require(['@/views/Private.vue'], resolve)
      },
      beforeEnter: ifAuthenticated,
      meta: { disableScroll: true }
    }

  ]
})
