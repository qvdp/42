<template>
  <v-layout align-center justify-center fill-height>
    <v-flex xs10 text-xs-center>
      <h3 class="pa-4">🔥 Waaw, Vous faites partie des rares à avoir accès à la partie <em>private</em> de cette app.</h3>
      <logout class="pa-4" />
    </v-flex>
  </v-layout>
</template>

<script>
import Logout from '@/components/LogoutButton'
export default {
  name: 'Private',
  components: { Logout }
}
</script>
