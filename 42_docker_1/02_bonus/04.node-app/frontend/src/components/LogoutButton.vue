<template>
  <div :class="{ 'ml-4':(isBlock === false) }">
    <v-btn large color="primary" class="text-none" @click="logout" :block="isBlock" :flat="isBlock" :loading="logoutLoading">
      Me déconnecter
    </v-btn>
  </div>
</template>

<script>
import { AUTH_LOGOUT } from '@/store/modules/entrance/actions/entrance.actions'

export default {
  name: 'Logout',
  props: {
    isBlock: {
      type: Boolean,
      default: false
    }
  },
  data () {
    return {
      logoutLoading: false
    }
  },
  methods: {
    logout () {
      this.$emit('is-loading')
      this.logoutLoading = true
      this.$store.dispatch(AUTH_LOGOUT)
        .finally(() => {
          delete localStorage.token
          this.$router.push({ name: 'Home' })
          this.logoutLoading = false
          this.$emit('is-loaded')
        })
    }
  }
}
</script>
