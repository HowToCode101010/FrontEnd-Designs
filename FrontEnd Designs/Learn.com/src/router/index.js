import { createRouter, createWebHistory} from 'vue-router'
import Home from '../views/Home.vue'
import Pricing from '../views/Pricing.vue'
import Courses from '../views/Courses.vue'

const router = createRouter({
    history: createWebHistory(),
    routes : [
        {
        path: '/',
        name: 'Home',
        component: Home
        },
        {
        path: '/pricing',
        name: 'Pricing',
        component: Pricing
        },
        {
        path: '/courses',
        name: 'Courses',
        component: Courses
        }
    ]
  }) 

export default router